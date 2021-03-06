#ifndef XTHREE_SKINNED_MESH_HPP
#define XTHREE_SKINNED_MESH_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xmesh_autogen.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // skinned_mesh declaration
    //

    template<class D>
    class xskinned_mesh : public xmesh<D>
    {
    public:

        using base_type = xmesh<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(std::string, derived_type, bindMode, "attached");
        XPROPERTY(matrix4, derived_type, bindMatrix, matrix4({1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}));
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, skeleton);
        XPROPERTY(std::string, derived_type, type, "SkinnedMesh");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xskinned_mesh();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using skinned_mesh = xw::xmaterialize<xskinned_mesh>;

    using skinned_mesh_generator = xw::xgenerator<xskinned_mesh>;

    //
    // skinned_mesh implementation
    //


    template <class D>
    inline void xskinned_mesh<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(bindMode, state, buffers);
        xw::set_patch_from_property(bindMatrix, state, buffers);
        xw::set_patch_from_property(skeleton, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xskinned_mesh<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(bindMode, patch, buffers);
        xw::set_property_from_patch(bindMatrix, patch, buffers);
        xw::set_property_from_patch(skeleton, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xskinned_mesh<D>::xskinned_mesh()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xskinned_mesh<D>::set_defaults()
    {
        this->_model_name() = "SkinnedMeshModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xskinned_mesh>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xskinned_mesh>;
        extern template xw::xmaterialize<xthree::xskinned_mesh>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xskinned_mesh>>;
        extern template class xw::xgenerator<xthree::xskinned_mesh>;
        extern template xw::xgenerator<xthree::xskinned_mesh>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xskinned_mesh>>;
    #endif
#endif

#endif