#ifndef XTHREE_IMMEDIATE_RENDER_OBJECT_HPP
#define XTHREE_IMMEDIATE_RENDER_OBJECT_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../../base/xenums.hpp"
#include "../../base/xthree_types.hpp"
#include "../../base/xthree.hpp"

namespace xthree
{
    //
    // immediate_render_object declaration
    //

    template<class D>
    class ximmediate_render_object : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);


    protected:

        ximmediate_render_object();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using immediate_render_object = xw::xmaterialize<ximmediate_render_object>;

    using immediate_render_object_generator = xw::xgenerator<ximmediate_render_object>;

    //
    // immediate_render_object implementation
    //

    template <class D>
    inline void ximmediate_render_object<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void ximmediate_render_object<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline ximmediate_render_object<D>::ximmediate_render_object()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void ximmediate_render_object<D>::set_defaults()
    {
        this->_model_name() = "ImmediateRenderObjectModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::ximmediate_render_object));
//}
#endif