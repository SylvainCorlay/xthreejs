#ifndef XTHREE_PLANE_GEOMETRY_HPP
#define XTHREE_PLANE_GEOMETRY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xbase_geometry_autogen.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // plane_geometry declaration
    //

    template<class D>
    class xplane_geometry : public xbase_geometry<D>
    {
    public:

        using base_type = xbase_geometry<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, width, 1);
        XPROPERTY(double, derived_type, height, 1);
        XPROPERTY(int, derived_type, widthSegments, 1);
        XPROPERTY(int, derived_type, heightSegments, 1);
        XPROPERTY(std::string, derived_type, type, "PlaneGeometry");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xplane_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using plane_geometry = xw::xmaterialize<xplane_geometry>;

    using plane_geometry_generator = xw::xgenerator<xplane_geometry>;

    //
    // plane_geometry implementation
    //


    template <class D>
    inline void xplane_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(width, state, buffers);
        xw::set_patch_from_property(height, state, buffers);
        xw::set_patch_from_property(widthSegments, state, buffers);
        xw::set_patch_from_property(heightSegments, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xplane_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(width, patch, buffers);
        xw::set_property_from_patch(height, patch, buffers);
        xw::set_property_from_patch(widthSegments, patch, buffers);
        xw::set_property_from_patch(heightSegments, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xplane_geometry<D>::xplane_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xplane_geometry<D>::set_defaults()
    {
        this->_model_name() = "PlaneGeometryModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xplane_geometry>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xplane_geometry>;
        extern template xw::xmaterialize<xthree::xplane_geometry>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xplane_geometry>>;
        extern template class xw::xgenerator<xthree::xplane_geometry>;
        extern template xw::xgenerator<xthree::xplane_geometry>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xplane_geometry>>;
    #endif
#endif

#endif