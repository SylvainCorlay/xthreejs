#ifndef XTHREE_DISCRETE_INTERPOLANT_HPP
#define XTHREE_DISCRETE_INTERPOLANT_HPP

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
    // discrete_interpolant declaration
    //

    template<class D>
    class xdiscrete_interpolant : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);


    protected:

        xdiscrete_interpolant();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using discrete_interpolant = xw::xmaterialize<xdiscrete_interpolant>;

    using discrete_interpolant_generator = xw::xgenerator<xdiscrete_interpolant>;

    //
    // discrete_interpolant implementation
    //

    template <class D>
    inline void xdiscrete_interpolant<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xdiscrete_interpolant<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xdiscrete_interpolant<D>::xdiscrete_interpolant()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xdiscrete_interpolant<D>::set_defaults()
    {
        this->_model_name() = "DiscreteInterpolantModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xdiscrete_interpolant));
//}
#endif