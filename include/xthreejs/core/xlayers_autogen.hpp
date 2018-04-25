#ifndef XTHREE_LAYERS_HPP
#define XTHREE_LAYERS_HPP

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
    // layers declaration
    //

    template<class D>
    class xlayers : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);


    protected:

        xlayers();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using layers = xw::xmaterialize<xlayers>;

    using layers_generator = xw::xgenerator<xlayers>;

    //
    // layers implementation
    //

    template <class D>
    inline void xlayers<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xlayers<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xlayers<D>::xlayers()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xlayers<D>::set_defaults()
    {
        this->_model_name() = "LayersModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xlayers));
//}
#endif