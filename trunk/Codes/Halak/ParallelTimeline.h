#pragma once
#ifndef __HALAK_GAMESUBTHREADNODE_H__
#define __HALAK_GAMESUBTHREADNODE_H__

#   include <Halak/BuildConfiguration.h>

#   if (defined(HALAK_PLATFORM_WINDOWS))
#       include <Halak/GameSubThreadNode.Windows.h>
#   endif

#endif