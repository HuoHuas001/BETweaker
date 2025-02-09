// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class BlockEventListener {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BLOCKEVENTLISTENER
public:
    class BlockEventListener& operator=(class BlockEventListener const &) = delete;
    BlockEventListener(class BlockEventListener const &) = delete;
    BlockEventListener() = delete;
#endif

public:
    /*0*/ virtual ~BlockEventListener();
    /*
    inline enum EventResult onBlockInteractedWith(class Player & a0, class BlockPos const & a1){
        enum EventResult (BlockEventListener::*rv)(class Player &, class BlockPos const &);
        *((void**)&rv) = dlsym("?onBlockInteractedWith@BlockEventListener@@UEAA?AW4EventResult@@AEAVPlayer@@AEBVBlockPos@@@Z");
        return (this->*rv)(std::forward<class Player &>(a0), std::forward<class BlockPos const &>(a1));
    }
    inline enum EventResult onBlockDestructionStopped(class Player & a0, class BlockPos const & a1, int a2){
        enum EventResult (BlockEventListener::*rv)(class Player &, class BlockPos const &, int);
        *((void**)&rv) = dlsym("?onBlockDestructionStopped@BlockEventListener@@UEAA?AW4EventResult@@AEAVPlayer@@AEBVBlockPos@@H@Z");
        return (this->*rv)(std::forward<class Player &>(a0), std::forward<class BlockPos const &>(a1), std::forward<int>(a2));
    }
    inline enum EventResult onBlockDestructionStarted(class Player & a0, class BlockPos const & a1){
        enum EventResult (BlockEventListener::*rv)(class Player &, class BlockPos const &);
        *((void**)&rv) = dlsym("?onBlockDestructionStarted@BlockEventListener@@UEAA?AW4EventResult@@AEAVPlayer@@AEBVBlockPos@@@Z");
        return (this->*rv)(std::forward<class Player &>(a0), std::forward<class BlockPos const &>(a1));
    }
    inline enum EventResult onEvent(struct BlockNotificationEvent const & a0){
        enum EventResult (BlockEventListener::*rv)(struct BlockNotificationEvent const &);
        *((void**)&rv) = dlsym("?onEvent@BlockEventListener@@UEAA?AW4EventResult@@AEBUBlockNotificationEvent@@@Z");
        return (this->*rv)(std::forward<struct BlockNotificationEvent const &>(a0));
    }
    inline enum EventResult onUnknownBlockReceived(class Level & a0, struct NewBlockID const & a1, unsigned short a2){
        enum EventResult (BlockEventListener::*rv)(class Level &, struct NewBlockID const &, unsigned short);
        *((void**)&rv) = dlsym("?onUnknownBlockReceived@BlockEventListener@@UEAA?AW4EventResult@@AEAVLevel@@AEBUNewBlockID@@G@Z");
        return (this->*rv)(std::forward<class Level &>(a0), std::forward<struct NewBlockID const &>(a1), std::forward<unsigned short>(a2));
    }
    inline enum EventResult onBlockModified(class BlockPos const & a0, class Block const & a1, class Block const & a2){
        enum EventResult (BlockEventListener::*rv)(class BlockPos const &, class Block const &, class Block const &);
        *((void**)&rv) = dlsym("?onBlockModified@BlockEventListener@@UEAA?AW4EventResult@@AEBVBlockPos@@AEBVBlock@@1@Z");
        return (this->*rv)(std::forward<class BlockPos const &>(a0), std::forward<class Block const &>(a1), std::forward<class Block const &>(a2));
    }
    inline enum EventResult onBlockDestroyedByPlayer(class Player & a0, class Block const & a1, class BlockPos const & a2){
        enum EventResult (BlockEventListener::*rv)(class Player &, class Block const &, class BlockPos const &);
        *((void**)&rv) = dlsym("?onBlockDestroyedByPlayer@BlockEventListener@@UEAA?AW4EventResult@@AEAVPlayer@@AEBVBlock@@AEBVBlockPos@@@Z");
        return (this->*rv)(std::forward<class Player &>(a0), std::forward<class Block const &>(a1), std::forward<class BlockPos const &>(a2));
    }
    inline enum EventResult onBlockPlacedByPlayer(class Player & a0, class Block const & a1, class BlockPos const & a2, bool a3){
        enum EventResult (BlockEventListener::*rv)(class Player &, class Block const &, class BlockPos const &, bool);
        *((void**)&rv) = dlsym("?onBlockPlacedByPlayer@BlockEventListener@@UEAA?AW4EventResult@@AEAVPlayer@@AEBVBlock@@AEBVBlockPos@@_N@Z");
        return (this->*rv)(std::forward<class Player &>(a0), std::forward<class Block const &>(a1), std::forward<class BlockPos const &>(a2), std::forward<bool>(a3));
    }
    inline enum EventResult onBlockExploded(class BlockPos const & a0, class Block const & a1, class Actor * a2){
        enum EventResult (BlockEventListener::*rv)(class BlockPos const &, class Block const &, class Actor *);
        *((void**)&rv) = dlsym("?onBlockExploded@BlockEventListener@@UEAA?AW4EventResult@@AEBVBlockPos@@AEBVBlock@@PEAVActor@@@Z");
        return (this->*rv)(std::forward<class BlockPos const &>(a0), std::forward<class Block const &>(a1), std::forward<class Actor *>(a2));
    }
    inline enum EventResult onBlockMovedByPiston(class BlockPos const & a0, class BlockPos const & a1, enum PistonState a2){
        enum EventResult (BlockEventListener::*rv)(class BlockPos const &, class BlockPos const &, enum PistonState);
        *((void**)&rv) = dlsym("?onBlockMovedByPiston@BlockEventListener@@UEAA?AW4EventResult@@AEBVBlockPos@@0W4PistonState@@@Z");
        return (this->*rv)(std::forward<class BlockPos const &>(a0), std::forward<class BlockPos const &>(a1), std::forward<enum PistonState>(a2));
    }
    */

protected:

private:

};