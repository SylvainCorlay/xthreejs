#ifndef XTHREE_STEREO_CAMERA_HPP
#define XTHREE_STEREO_CAMERA_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // stereo_camera declaration
    //

    template<class D>
    class xstereo_camera : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, aspect, 1);
        XPROPERTY(double, derived_type, eyeSep, 0.064);
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, cameraL);
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, cameraR);


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xstereo_camera();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using stereo_camera = xw::xmaterialize<xstereo_camera>;

    using stereo_camera_generator = xw::xgenerator<xstereo_camera>;

    //
    // stereo_camera implementation
    //


    template <class D>
    inline void xstereo_camera<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(aspect, state, buffers);
        xw::set_patch_from_property(eyeSep, state, buffers);
        xw::set_patch_from_property(cameraL, state, buffers);
        xw::set_patch_from_property(cameraR, state, buffers);
    }

    template <class D>
    inline void xstereo_camera<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(aspect, patch, buffers);
        xw::set_property_from_patch(eyeSep, patch, buffers);
        xw::set_property_from_patch(cameraL, patch, buffers);
        xw::set_property_from_patch(cameraR, patch, buffers);
    }

    template <class D>
    inline xstereo_camera<D>::xstereo_camera()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xstereo_camera<D>::set_defaults()
    {
        this->_model_name() = "StereoCameraModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xstereo_camera>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xstereo_camera>;
        extern template xw::xmaterialize<xthree::xstereo_camera>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xstereo_camera>>;
        extern template class xw::xgenerator<xthree::xstereo_camera>;
        extern template xw::xgenerator<xthree::xstereo_camera>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xstereo_camera>>;
    #endif
#endif

#endif