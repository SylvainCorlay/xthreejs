#ifndef XTHREE_BOX3_HPP
#define XTHREE_BOX3_HPP

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
    // box3 declaration
    //

    template<class D>
    class xbox3 : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(vector3, derived_type, min, vector3({0,0,0}));
        XPROPERTY(vector3, derived_type, max, vector3({0,0,0}));

    protected:

        xbox3();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using box3 = xw::xmaterialize<xbox3>;

    using box3_generator = xw::xgenerator<xbox3>;

    //
    // box3 implementation
    //

    template <class D>
    inline void xbox3<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(min, state, buffers);
        xw::set_patch_from_property(max, state, buffers);
    }

    template <class D>
    inline void xbox3<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(min, patch, buffers);
        xw::set_property_from_patch(max, patch, buffers);
    }

    template <class D>
    inline xbox3<D>::xbox3()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xbox3<D>::set_defaults()
    {
        this->_model_name() = "Box3Model";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xbox3));
//}
#endif