#ifndef XTHREE_CATMULL_ROM_CURVE3_HPP
#define XTHREE_CATMULL_ROM_CURVE3_HPP

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
    // catmull_rom_curve3 declaration
    //

    template<class D>
    class xcatmull_rom_curve3 : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);


    protected:

        xcatmull_rom_curve3();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using catmull_rom_curve3 = xw::xmaterialize<xcatmull_rom_curve3>;

    using catmull_rom_curve3_generator = xw::xgenerator<xcatmull_rom_curve3>;

    //
    // catmull_rom_curve3 implementation
    //

    template <class D>
    inline void xcatmull_rom_curve3<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xcatmull_rom_curve3<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xcatmull_rom_curve3<D>::xcatmull_rom_curve3()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xcatmull_rom_curve3<D>::set_defaults()
    {
        this->_model_name() = "CatmullRomCurve3Model";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xcatmull_rom_curve3));
//}
#endif