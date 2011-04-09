#pragma once
#ifndef __HALAK_SAMPLES_H__
#define __HALAK_SAMPLES_H__

#   include <Halak/String.h>
#   include <vector>
    using Halak::String;

    namespace Halak
    {
        namespace Samples
        {
            void AnySample(const std::vector<const char*>& args);
            void FileSystemSample(const std::vector<const char*>& args);
            void ReflectionSample(const std::vector<const char*>& args);
            void StringSample(const std::vector<const char*>& args);
            void SignalSample(const std::vector<const char*>& args);
            void JSONSample(const std::vector<const char*>& args);
            void LuaSample(const std::vector<const char*>& args);
            void SharedPointerSample(const std::vector<const char*>& args);

            void SwapChainSample(const std::vector<const char*>& args);
            void ParticleSample(const std::vector<const char*>& args);
            void SequentialParticleSample(const std::vector<const char*>& args);

            void GameComponentSample(const std::vector<const char*>& args);
        }
    }

#endif