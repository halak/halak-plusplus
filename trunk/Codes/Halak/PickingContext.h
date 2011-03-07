#pragma once
#ifndef __HALAK_PICKINGCONTEXT_H__
#define __HALAK_PICKINGCONTEXT_H__

#   include <Halak/FWD.h>
#   include <Halak/Any.h>
#   include <Halak/Ray.h>
#   include <list>

    namespace Halak
    {
        struct PickResult
        {
            float   Distance;
            Vector3 Point;
            Vector3 Normal;
            IPickable*   Object;
            IPickablePtr SharedObject;
            Any ExtraData;

            inline PickResult(float distance, Vector3 point, Vector3 normal, IPickable* object, const Any& extraData);
            inline PickResult(float distance, Vector3 point, Vector3 normal, IPickablePtr sharedObject, const Any& extraData);
            inline PickResult(const PickResult& original);

            inline PickResult& operator = (const PickResult& right);
            inline bool operator == (const PickResult& right) const;
            inline bool operator != (const PickResult& right) const;
        };

        class PickingContext
        {
            public:
                typedef std::list<PickResult> ResultCollection;

            public:
                PickingContext(const Ray& ray, bool ordered, bool findAll, bool debug);
                PickingContext(const PickingContext& original);

                bool Push(const PickResult& result);

                inline const Ray& GetRay() const;
                inline bool IsOrdered() const;
                inline bool IsFindAll() const;
                inline bool IsDebug() const;
                inline const ResultCollection& GetResults() const;

                PickingContext& operator = (const PickingContext& right);
                bool operator == (const PickingContext& right) const;
                bool operator != (const PickingContext& right) const;

            private:
                enum OptionFlags
                {
                    OrderedFlag = (1 << 0),
                    FindAllFlag = (1 << 1),
                    DebugFlag = (1 << 2),
                };
                static dword MakeOptions(bool ordered, bool findAll, bool debug);

            private:
                Ray ray;
                dword options;

                ResultCollection results;
        };

        typedef PickingContext::ResultCollection PickResultCollection;
    }

#   include <Halak/PickingContext.inl>

#endif