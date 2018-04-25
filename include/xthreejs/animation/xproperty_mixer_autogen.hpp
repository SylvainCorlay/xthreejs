#ifndef XTHREE_PROPERTY_MIXER_HPP
#define XTHREE_PROPERTY_MIXER_HPP

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
    // property_mixer declaration
    //

    template<class D>
    class xproperty_mixer : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);


    protected:

        xproperty_mixer();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using property_mixer = xw::xmaterialize<xproperty_mixer>;

    using property_mixer_generator = xw::xgenerator<xproperty_mixer>;

    //
    // property_mixer implementation
    //

    template <class D>
    inline void xproperty_mixer<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xproperty_mixer<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xproperty_mixer<D>::xproperty_mixer()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xproperty_mixer<D>::set_defaults()
    {
        this->_model_name() = "PropertyMixerModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xproperty_mixer));
//}
#endif