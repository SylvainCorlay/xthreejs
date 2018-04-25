#ifndef XTHREE_RAY_HPP
#define XTHREE_RAY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"

namespace xthree
{
    //
    // ray declaration
    //

    template<class D>
    class xray : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(vector3, derived_type, origin, vector3({0,0,0}));
        XPROPERTY(vector3, derived_type, direction, vector3({0,0,0}));

    protected:

        xray();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using ray = xw::xmaterialize<xray>;

    using ray_generator = xw::xgenerator<xray>;

    //
    // ray implementation
    //

    template <class D>
    inline void xray<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(origin, state, buffers);
        xw::set_patch_from_property(direction, state, buffers);
    }

    template <class D>
    inline void xray<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(origin, patch, buffers);
        xw::set_property_from_patch(direction, patch, buffers);
    }

    template <class D>
    inline xray<D>::xray()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xray<D>::set_defaults()
    {
        this->_model_name() = "RayModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xray));
//}
#endif