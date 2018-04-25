#ifndef XTHREE_WEBGL_INDEXED_BUFFER_RENDERER_HPP
#define XTHREE_WEBGL_INDEXED_BUFFER_RENDERER_HPP

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
    // webgl_indexed_buffer_renderer declaration
    //

    template<class D>
    class xwebgl_indexed_buffer_renderer : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);


    protected:

        xwebgl_indexed_buffer_renderer();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using webgl_indexed_buffer_renderer = xw::xmaterialize<xwebgl_indexed_buffer_renderer>;

    using webgl_indexed_buffer_renderer_generator = xw::xgenerator<xwebgl_indexed_buffer_renderer>;

    //
    // webgl_indexed_buffer_renderer implementation
    //

    template <class D>
    inline void xwebgl_indexed_buffer_renderer<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xwebgl_indexed_buffer_renderer<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xwebgl_indexed_buffer_renderer<D>::xwebgl_indexed_buffer_renderer()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xwebgl_indexed_buffer_renderer<D>::set_defaults()
    {
        this->_model_name() = "WebGLIndexedBufferRendererModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xwebgl_indexed_buffer_renderer));
//}
#endif