#ifndef XTHREE_WEBGL_GEOMETRIES_HPP
#define XTHREE_WEBGL_GEOMETRIES_HPP

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
    // webgl_geometries declaration
    //

    template<class D>
    class xwebgl_geometries : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);


    protected:

        xwebgl_geometries();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using webgl_geometries = xw::xmaterialize<xwebgl_geometries>;

    using webgl_geometries_generator = xw::xgenerator<xwebgl_geometries>;

    //
    // webgl_geometries implementation
    //

    template <class D>
    inline void xwebgl_geometries<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xwebgl_geometries<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xwebgl_geometries<D>::xwebgl_geometries()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xwebgl_geometries<D>::set_defaults()
    {
        this->_model_name() = "WebGLGeometriesModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xwebgl_geometries));
//}
#endif