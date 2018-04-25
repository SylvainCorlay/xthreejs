#ifndef XTHREE_LINE_DASHED_MATERIAL_HPP
#define XTHREE_LINE_DASHED_MATERIAL_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xmaterial_autogen.hpp"

namespace xthree
{
    //
    // line_dashed_material declaration
    //

    template<class D>
    class xline_dashed_material : public xmaterial<D>
    {
    public:

        using base_type = xmaterial<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xw::html_color, derived_type, color, "#ffffff");
        XPROPERTY(bool, derived_type, lights, false);
        XPROPERTY(double, derived_type, linewidth, 1);
        XPROPERTY(double, derived_type, scale, 1);
        XPROPERTY(double, derived_type, dashSize, 3);
        XPROPERTY(double, derived_type, gapSize, 1);

    protected:

        xline_dashed_material();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using line_dashed_material = xw::xmaterialize<xline_dashed_material>;

    using line_dashed_material_generator = xw::xgenerator<xline_dashed_material>;

    //
    // line_dashed_material implementation
    //

    template <class D>
    inline void xline_dashed_material<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(color, state, buffers);
        xw::set_patch_from_property(lights, state, buffers);
        xw::set_patch_from_property(linewidth, state, buffers);
        xw::set_patch_from_property(scale, state, buffers);
        xw::set_patch_from_property(dashSize, state, buffers);
        xw::set_patch_from_property(gapSize, state, buffers);
    }

    template <class D>
    inline void xline_dashed_material<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(color, patch, buffers);
        xw::set_property_from_patch(lights, patch, buffers);
        xw::set_property_from_patch(linewidth, patch, buffers);
        xw::set_property_from_patch(scale, patch, buffers);
        xw::set_property_from_patch(dashSize, patch, buffers);
        xw::set_property_from_patch(gapSize, patch, buffers);
    }

    template <class D>
    inline xline_dashed_material<D>::xline_dashed_material()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xline_dashed_material<D>::set_defaults()
    {
        this->_model_name() = "LineDashedMaterialModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xline_dashed_material));
//}
#endif