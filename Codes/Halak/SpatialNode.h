//#ifndef __HALAK_SPATIALNODE_H__
//#define __HALAK_SPATIALNODE_H__
//
//#   include <Halak/FWD.h>
//#   include <Halak/ISpatial.h>
//#   include <Halak/IRevisable.h>
//#   include <vector>
//
//    namespace Halak
//    {
//        class SpatialNode : public ISpatial, public IRevisable
//        {
//            private:
//                struct Child
//                {
//                    ISpatialPtr child;
//                    int revision;
//                };
//
//            public:
//                typedef std::vector<ISpatialPtr> SpatialCollection;
//                typedef std::vector<Child> ChildCollection;
//
//            public:
//                SpatialNode();
//                virtual ~SpatialNode();
//
//                virtual Vector3 GetPosition();
//                virtual void SetPosition(Vector3 value);
//
//                virtual Quaternion GetRotation();
//                virtual void SetRotation(Quaternion value);
//
//                virtual float GetScale();
//                virtual void  SetScale(float value);
//
//                Vector3 GetLocalPosition() const;
//                void SetLocalPosition(Vector3 value);
//
//                Quaternion GetLocalRotation() const;
//                void SetLocalRotation(Quaternion value);
//
//                float GetLocalScale() const;
//                void  SetLocalScale(float value);
//
//                virtual uint GetRevision() const;
//
//            private:
//                void UpdateWorldTransform() const;
//
//            private:
//                Vector3    localPosition;
//                Quaternion localRotation;
//                float      localScale;
//                bool       localTransformChanged;
//
//                ISpatialWeakPtr parent;
//                uint parentRevision;
//
//                ChildCollection children;
//                SpatialCollection childSpatials;
//
//                Vector3    globalPosition;
//                Quaternion globalRotation;
//                float      globalScale;
//
//                //Vector3 worldPosition;
//                //Quaternion worldRotation;
//                //float worldScale;
//                //uint parentRevision;
//
//                //Vector3 localPosition;
//                //Quaternion localRotation;
//                //float localScale;
//                //uint revision;
//                //bool worldTransformChanged;
//
//                //ISpatialWeakPtr parent;
//                //ChildCollection children;
//                //SpatialCollection childSpatials;
//        };
//    }
//
//#endif