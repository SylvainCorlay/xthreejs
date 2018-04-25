#ifndef XTHREE_TORUS_GEOMETRY_HPP
#define XTHREE_TORUS_GEOMETRY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xbase_geometry_autogen.hpp"

namespace xthree
{
    //
    // torus_geometry declaration
    //

    template<class D>
    class xtorus_geometry : public xbase_geometry<D>
    {
    public:

        using base_type = xbase_geometry<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, radius, 1);
        XPROPERTY(double, derived_type, tube, 0.4);
        XPROPERTY(int, derived_type, radialSegments, 8);
        XPROPERTY(int, derived_type, tubularSegments, 6);
        XPROPERTY(double, derived_type, arc, 6.283185307179586);

    protected:

        xtorus_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using torus_geometry = xw::xmaterialize<xtorus_geometry>;

    using torus_geometry_generator = xw::xgenerator<xtorus_geometry>;

    //
    // torus_geometry implementation
    //

    template <class D>
    inline void xtorus_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(radius, state, buffers);
        xw::set_patch_from_property(tube, state, buffers);
        xw::set_patch_from_property(radialSegments, state, buffers);
        xw::set_patch_from_property(tubularSegments, state, buffers);
        xw::set_patch_from_property(arc, state, buffers);
    }

    template <class D>
    inline void xtorus_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(radius, patch, buffers);
        xw::set_property_from_patch(tube, patch, buffers);
        xw::set_property_from_patch(radialSegments, patch, buffers);
        xw::set_property_from_patch(tubularSegments, patch, buffers);
        xw::set_property_from_patch(arc, patch, buffers);
    }

    template <class D>
    inline xtorus_geometry<D>::xtorus_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xtorus_geometry<D>::set_defaults()
    {
        this->_model_name() = "TorusGeometryModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xtorus_geometry));
//}
#endif