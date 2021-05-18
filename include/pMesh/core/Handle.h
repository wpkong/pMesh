/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/15
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_HANDLE_H
#define PMESH_HANDLE_H

namespace pMesh{
    class BaseHandle {
    public:
        int index = -1;

    public:
        explicit BaseHandle(int index = -1) : index(index) {}

        explicit BaseHandle(const BaseHandle &handle): index(handle.index) {}

    public:
        int id() const { return index; }

    public:
        bool operator==(const BaseHandle &handle) const {
            return this->index == handle.index;
        }

        bool operator<(const BaseHandle &handle) const {
            return this->index < handle.index;
        }

        bool operator<=(const BaseHandle &handle) const {
            return this->index <= handle.index;
        }

        bool operator>(const BaseHandle &handle) const {
            return this->index > handle.index;
        }

        bool operator>=(const BaseHandle &handle) const {
            return this->index >= handle.index;
        }

        bool is_valid() const {
            return this->index != -1;
        }

        virtual BaseHandle &operator=(int index) {
            this->index = index;
            return *this;
        }

        BaseHandle& operator=(const BaseHandle &handle) = default;

        virtual explicit operator int() const {
            return index;
        }
    };
}

namespace pMesh::Surface{
    class VertexHandle: public BaseHandle{
    public:
        explicit VertexHandle(int index = -1): BaseHandle(index){}

        VertexHandle &operator=(int index) final {
            this->index = index;
            return *this;
        }

        explicit operator int() const override {
            return index;
        }
    };

    class HalfEdgeHandle: public BaseHandle{
    public:
        explicit HalfEdgeHandle(int index = -1): BaseHandle(index){}

        HalfEdgeHandle &operator=(int index) final {
            this->index = index;
            return *this;
        }

        explicit operator int() const override {
            return index;
        }
    };

    class EdgeHandle: public BaseHandle{
    public:
        explicit EdgeHandle(int index = -1): BaseHandle(index){}

        EdgeHandle &operator=(int index) final {
            this->index = index;
            return *this;
        }

        explicit operator int() const override {
            return index;
        }
    };

    class FaceHandle: public BaseHandle{
    public:
        explicit FaceHandle(int index = -1): BaseHandle(index){}

        FaceHandle &operator=(int index) final {
            this->index = index;
            return *this;
        }

        explicit operator int() const override {
            return index;
        }
    };
}


namespace pMesh::Volume{
    class VertexHandle: public BaseHandle{
    public:
        explicit VertexHandle(int index = -1): BaseHandle(index){}

        VertexHandle &operator=(int index) final {
            this->index = index;
            return *this;
        }

        explicit operator int() const override {
            return index;
        }
    };

    class HalfEdgeHandle: public BaseHandle{
    public:
        explicit HalfEdgeHandle(int index = -1): BaseHandle(index){}

        HalfEdgeHandle &operator=(int index) final {
            this->index = index;
            return *this;
        }

        explicit operator int() const override {
            return index;
        }
    };

    class EdgeHandle: public BaseHandle{
    public:
        explicit EdgeHandle(int index = -1): BaseHandle(index){}

        EdgeHandle &operator=(int index) final {
            this->index = index;
            return *this;
        }

        explicit operator int() const override {
            return index;
        }
    };

    class CellHandle: public BaseHandle{
    public:
        explicit CellHandle(int index = -1): BaseHandle(index){}

        CellHandle &operator=(int index) final {
            this->index = index;
            return *this;
        }

        explicit operator int() const override {
            return index;
        }
    };

    class HalfFaceHandle: public BaseHandle{
    public:
        explicit HalfFaceHandle(int index = -1): BaseHandle(index){}

        HalfFaceHandle &operator=(int index) final {
            this->index = index;
            return *this;
        }

        explicit operator int() const override {
            return index;
        }
    };


    class FaceHandle: public BaseHandle{
    public:
        explicit FaceHandle(int index = -1): BaseHandle(index){}

        FaceHandle &operator=(int index) final {
            this->index = index;
            return *this;
        }

        explicit operator int() const override {
            return index;
        }
    };

}


#endif //PMESH_HANDLE_H
