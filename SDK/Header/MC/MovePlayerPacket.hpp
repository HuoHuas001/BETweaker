// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Player.hpp"
#include "Packet.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here
enum TeleportationCause {
    UNKNOWN,
    PROJECTILE,
    CHORUS_FRUIT,
    COMMAND,
    BEHAVIOR,
};
#undef BEFORE_EXTRA

class MovePlayerPacket : public Packet {

#define AFTER_EXTRA
// Add Member There
public:
    unsigned long long runtimeId;
    Vec3 position;
    float pitch;
    float yaw;
    float headYaw;
    Player::PositionMode mode;
    bool onGround;
    unsigned long long ridingRuntimeId;
    TeleportationCause teleportationCause;
    int entityType;
    long tick;
    
    inline std::string toDebugString() {
        return fmt::format("{}: pos: {}, mode: {}, cause: {}",
            __super::toDebugString(), position.toString(), (int)mode, int(teleportationCause));
    }

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MOVEPLAYERPACKET
public:
    class MovePlayerPacket& operator=(class MovePlayerPacket const &) = delete;
    MovePlayerPacket(class MovePlayerPacket const &) = delete;
#endif

public:
    /*0*/ virtual ~MovePlayerPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream &) const;
    /*6*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream &);
    /*
    inline  ~MovePlayerPacket(){
         (MovePlayerPacket::*rv)();
        *((void**)&rv) = dlsym("??1MovePlayerPacket@@UEAA@XZ");
        return (this->*rv)();
    }
    */
    MCAPI MovePlayerPacket(class Player const &, class Vec3 const &);
    MCAPI MovePlayerPacket(class Player const &, enum Player::PositionMode, int, int);
    MCAPI MovePlayerPacket();

protected:

private:

};