/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/12
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_HANDLE_H
#define PMESH_HANDLE_H

#include <pMesh/Common.h>

namespace pMesh {
    class Handle {
    protected:
        int index = -1;

    public:
        explicit Handle(int index = -1) : index(index) {}

        explicit Handle(const Handle &handle): index(handle.index) {}

    public:
        int id() const { return index; }

    public:
        bool operator==(const Handle &handle) const {
            return this->index == handle.index;
        }

        bool operator<(const Handle &handle) const {
            return this->index < handle.index;
        }

        bool operator<=(const Handle &handle) const {
            return this->index <= handle.index;
        }

        bool operator>(const Handle &handle) const {
            return this->index > handle.index;
        }

        bool operator>=(const Handle &handle) const {
            return this->index >= handle.index;
        }

        virtual Handle &operator=(int index) {
            this->index = index;
            return *this;
        }

        Handle& operator=(const Handle &handle) = default;

        virtual explicit operator int() const {
            return index;
        }
    };
}

namespace pMesh{
    class VertexHandle: public Handle{
    public:
        explicit VertexHandle(int index = -1): Handle(index){}

        VertexHandle &operator=(int index) final {
            this->index = index;
            return *this;
        }

        explicit operator int() const override {
            return index;
        }
    };

    class HalfEdgeHandle: public Handle{
    public:
        explicit HalfEdgeHandle(int index = -1): Handle(index){}

        HalfEdgeHandle &operator=(int index) final {
            this->index = index;
            return *this;
        }

        explicit operator int() const override {
            return index;
        }
    };

    class EdgeHandle: public Handle{
    public:
        explicit EdgeHandle(int index = -1): Handle(index){}

        EdgeHandle &operator=(int index) final {
            this->index = index;
            return *this;
        }

        explicit operator int() const override {
            return index;
        }
    };

    class CellHandle: public Handle{
    public:
        explicit CellHandle(int index = -1): Handle(index){}

        CellHandle &operator=(int index) final {
            this->index = index;
            return *this;
        }

        explicit operator int() const override {
            return index;
        }
    };
}

#endif //PMESH_HANDLE_H
