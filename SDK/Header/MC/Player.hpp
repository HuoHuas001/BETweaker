// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"
#include "Mob.hpp"

#define BEFORE_EXTRA
// Add include headers & pre-declares
    class ServerPlayer;
    class Player;
    class NetworkIdentifier;
    class UserEntityIdentifierComponent;
    class Certificate;
    class Container;
    class CompoundTag;
    #include "ScorePacketInfo.hpp"
    #include "DataItem.hpp"
#undef BEFORE_EXTRA

class Player : public Mob {

#define AFTER_EXTRA
// Add new members to class
public:
    enum PositionMode : char{
        NORMAL,
        RESPAWN,
        TELEPORT,
        HEAD_ROTATION,
    };

    LIAPI std::string getName();
    LIAPI std::string getRealName();
    LIAPI std::string getUuid();
    LIAPI unsigned char getClientSubId();
    LIAPI string getDeviceTypeName();
    LIAPI int getAvgPing();
    LIAPI int getLastPing();
    LIAPI std::string getIP();
    LIAPI string getLanguageCode();
    LIAPI string getServerAddress();
    LIAPI NetworkIdentifier* getNetworkIdentifier();
    LIAPI Certificate* getCertificate();
    LIAPI Container* getEnderChestContainer();
    LIAPI std::pair<BlockPos, int> getRespawnPosition();
    LIAPI float getAvgPacketLoss();
    LIAPI string getClientId();
    LIAPI int getDeviceType();
    LIAPI bool isOperator();
    LIAPI bool isOP();


    LIAPI bool sendText(string text, TextType type = TextType::RAW);
    template <typename... Args>
    bool sendFormattedText(string text, const Args&... args)
    {
        if constexpr (0 == sizeof...(args))
        {
            // Avoid fmt if only one argument
            return sendText(text, TextType::TIP);
        }
        else
            return sendText(fmt::format(text, args...), TextType::TIP);
    }

    LIAPI bool kick(const string& msg);
    LIAPI bool crashClient();
    LIAPI bool talkAs(const string& msg);
    LIAPI bool giveItem(ItemStack* item); 
    LIAPI int clearItem(string typeName);
    LIAPI bool runcmd(const string& cmd);
    LIAPI bool transferServer(const string& address, unsigned short port);
    LIAPI bool setSidebar(const std::string& title, const std::vector<std::pair<std::string, int>>& data, ObjectiveSortOrder sortOrder);
    LIAPI bool removeSidebar();
    LIAPI std::unique_ptr<CompoundTag> getNbt();
    LIAPI bool setNbt(CompoundTag* nbt);
    LIAPI bool refreshAttribute(class Attribute const& attribute);
    LIAPI bool refreshAttributes(std::vector<Attribute const*> const& attributes);

    LIAPI int getScore(const string& key);
    LIAPI bool setScore(const string& key, int value);
    LIAPI bool addScore(const string& key, int value);
    LIAPI bool reduceScore(const string& key, int value);
    LIAPI bool deleteScore(const string& key);

    //Form
    LIAPI bool sendSimpleForm(const string& title, const string& content, const vector<string>& buttons, const std::vector<std::string>& images, std::function<void(Player*, int)> callback) const;
    LIAPI bool sendModalForm(const string& title, const string& content, const string& button1, const string& button2, std::function<void(Player*, bool)> callback) const;
    LIAPI bool sendCustomForm(const std::string& data, std::function<void(Player*, string)> callback) const;

    //Packet
    LIAPI bool sendTextPacket(string text, TextType Type = TextType::RAW) const;
    LIAPI bool sendTitlePacket(string text, TitleType Type, int FadeInDuration, int RemainDuration, int FadeOutDuration) const;
    LIAPI bool sendNotePacket(unsigned int tone);
    LIAPI bool sendSpawnParticleEffectPacket(Vec3 spawnPos, int dimid, string ParticleName, int64_t EntityUniqueID = -1) const;
    /*bad*/ LIAPI bool sendPlaySoundPacket(string SoundName, Vec3 Position, float Volume, float Pitch) const;
    LIAPI bool sendAddItemEntityPacket(unsigned long long runtimeID, class Item const& item, int stackSize, short aux, Vec3 pos, vector<std::unique_ptr<DataItem>> dataItems = {}) const;
    LIAPI bool sendAddEntityPacket(unsigned long long runtimeID, string entityType, Vec3 pos, Vec2 rotation, float headYaw, vector<std::unique_ptr<DataItem>> dataItems = {});
    LIAPI bool sendUpdateBlockPacket(BlockPos const& blockPos, unsigned int runtimeId, UpdateBlockFlags flag = UpdateBlockFlags::BlockUpdateAll, UpdateBlockLayer layer = UpdateBlockLayer::UpdateBlockDefault);
    LIAPI bool sendUpdateBlockPacket(BlockPos const& blockPos, const Block& block, UpdateBlockFlags flag = UpdateBlockFlags::BlockUpdateAll, UpdateBlockLayer layer = UpdateBlockLayer::UpdateBlockDefault);
    LIAPI bool sendTransferPacket(const string& address, short port) const;
    LIAPI bool sendSetDisplayObjectivePacket(const string& title, const string& name, char sortOrder) const;
    LIAPI bool sendSetScorePacket(char type, const vector<ScorePacketInfo>& data);
    LIAPI bool sendBossEventPacket(BossEvent type, string name, float percent, BossEventColour colour, int overlay = 0);
    LIAPI bool sendCommandRequestPacket(const string& cmd);
    LIAPI bool sendTextTalkPacket(const string& msg);
    LIAPI bool sendTextTalkPacket(const string& msg, Player* target/* = nullptr*/);

    LIAPI bool sendRawFormPacket(unsigned formId, const string& data) const;

    LIAPI static bool isValid(Player* player);

    //For compatibility
    inline string getDeviceName() { return getDeviceTypeName(); }
    LIAPI bool sendSimpleFormPacket(const string& title, const string& content, const vector<string>& buttons, const std::vector<std::string>& images, std::function<void(int)> callback) const;
    LIAPI bool sendModalFormPacket(const string& title, const string& content, const string& button1, const string& button2, std::function<void(bool)> callback);
    LIAPI bool sendCustomFormPacket(const std::string& data, std::function<void(string)> callback);

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PLAYER
public:
    class Player& operator=(class Player const &) = delete;
    Player(class Player const &) = delete;
    Player() = delete;
#endif

public:
    /*8*/ virtual void reloadHardcoded(enum Actor::InitializationMethod, class VariantParameterList const &);
    /*10*/ virtual void initializeComponents(enum Actor::InitializationMethod, class VariantParameterList const &);
    /*12*/ virtual void _serverInitItemStackIds();
    /*14*/ virtual ~Player();
    /*16*/ virtual void resetUserPos(bool);
    /*18*/ virtual void remove();
    /*20*/ virtual bool isRuntimePredictedMovementEnabled() const;
    /*25*/ virtual class Vec3 getAttachPos(enum ActorLocation, float) const;
    /*28*/ virtual void move(class Vec3 const &);
    /*29*/ virtual void move(struct IActorMovementProxy &, class Vec3 const &) const;
    /*40*/ virtual void __unk_vfn_40();
    /*43*/ virtual void teleportTo(class Vec3 const &, bool, int, int);
    /*47*/ virtual std::unique_ptr<class AddActorBasePacket> tryCreateAddActorPacket();
    /*48*/ virtual void normalTick();
    /*50*/ virtual void vehicleTick();
    /*52*/ virtual float getRidingHeight();
    /*61*/ virtual void __unk_vfn_61();
    /*65*/ virtual std::string getFormattedNameTag() const;
    /*68*/ virtual void __unk_vfn_68();
    /*76*/ virtual void setBlockMovementSlowdownMultiplier(class BlockLegacy const &, class Vec3 const &);
    /*78*/ virtual float getCameraOffset() const;
    /*82*/ virtual void __unk_vfn_82();
    /*85*/ virtual bool canInteractWithOtherEntitiesInGame() const;
    /*88*/ virtual void __unk_vfn_88();
    /*89*/ virtual void playerTouch(class Player &);
    /*92*/ virtual bool isImmobile() const;
    /*95*/ virtual void __unk_vfn_95();
    /*96*/ virtual bool isSleeping() const;
    /*97*/ virtual void setSleeping(bool);
    /*98*/ virtual void __unk_vfn_98();
    /*100*/ virtual bool isBlocking() const;
    /*101*/ virtual bool isDamageBlocked(class ActorDamageSource const &) const;
    /*105*/ virtual void __unk_vfn_105();
    /*107*/ virtual void __unk_vfn_107();
    /*108*/ virtual void __unk_vfn_108();
    /*109*/ virtual void __unk_vfn_109();
    /*113*/ virtual class Actor * findAttackTarget();
    /*114*/ virtual bool isValidTarget(class Actor *) const;
    /*115*/ virtual bool attack(class Actor &, enum ActorDamageCause const &);
    /*120*/ virtual void onTame();
    /*121*/ virtual void onFailedTame();
    /*128*/ virtual bool isJumping() const;
    /*130*/ virtual void vehicleLanded(class Vec3 const &, class Vec3 const &);
    /*134*/ virtual bool isInvulnerableTo(class ActorDamageSource const &) const;
    /*139*/ virtual void onBounceStarted(class BlockPos const &, class Block const &);
    /*140*/ virtual void feed(int);
    /*141*/ virtual void handleEntityEvent(enum ActorEvent, int);
    /*143*/ virtual class HashedString const & getActorRendererId() const;
    /*151*/ virtual void awardKillScore(class Actor &, int);
    /*152*/ virtual void setArmor(enum ArmorSlot, class ItemStack const &);
    /*160*/ virtual class ItemStack const & getCarriedItem() const;
    /*161*/ virtual void setCarriedItem(class ItemStack const &);
    /*162*/ virtual void setOffhandSlot(class ItemStack const &);
    /*163*/ virtual class ItemStack const & getEquippedTotem() const;
    /*164*/ virtual bool consumeTotem();
    /*169*/ virtual enum ActorType getEntityTypeId() const;
    /*171*/ virtual struct ActorUniqueID getSourceUniqueID() const;
    /*173*/ virtual bool canFreeze() const;
    /*177*/ virtual int getPortalCooldown() const;
    /*178*/ virtual int getPortalWaitTime() const;
    /*180*/ virtual bool canChangeDimensions() const;
    /*181*/ virtual void __unk_vfn_181();
    /*183*/ virtual struct ActorUniqueID getControllingPlayer() const;
    /*190*/ virtual void onSynchedDataUpdate(int);
    /*191*/ virtual bool canAddPassenger(class Actor &) const;
    /*192*/ virtual bool canPickupItem(class ItemStack const &) const;
    /*193*/ virtual bool canBePulledIntoVehicle() const;
    /*195*/ virtual void __unk_vfn_195();
    /*197*/ virtual void sendMotionPacketIfNeeded();
    /*198*/ virtual bool canSynchronizeNewEntity() const;
    /*200*/ virtual void startSwimming();
    /*201*/ virtual void stopSwimming();
    /*203*/ virtual enum CommandPermissionLevel getCommandPermissionLevel() const;
    /*216*/ virtual class AnimationComponent & getAnimationComponent();
    /*219*/ virtual void useItem(class ItemStackBase &, enum ItemUseMethod, bool);
    /*220*/ virtual void __unk_vfn_220();
    /*221*/ virtual void __unk_vfn_221();
    /*223*/ virtual float getMapDecorationRotation() const;
    /*228*/ virtual bool isWorldBuilder() const;
    /*229*/ virtual bool isCreative() const;
    /*230*/ virtual bool isAdventure() const;
    /*231*/ virtual bool isSurvival() const;
    /*232*/ virtual bool isSpectator() const;
    /*234*/ virtual bool add(class ItemStack &);
    /*235*/ virtual bool drop(class ItemStack const &, bool);
    /*237*/ virtual bool canDestroyBlock(class Block const &) const;
    /*238*/ virtual void setAuxValue(int);
    /*239*/ virtual void setSize(float, float);
    /*243*/ virtual void startSpinAttack();
    /*244*/ virtual void stopSpinAttack();
    /*246*/ virtual void __unk_vfn_246();
    /*249*/ virtual void __unk_vfn_249();
    /*251*/ virtual void die(class ActorDamageSource const &);
    /*252*/ virtual bool shouldDropDeathLoot() const;
    /*261*/ virtual void __unk_vfn_261();
    /*262*/ virtual bool _hurt(class ActorDamageSource const &, float, bool, bool);
    /*265*/ virtual void readAdditionalSaveData(class CompoundTag const &, class DataLoadHelper &);
    /*266*/ virtual void addAdditionalSaveData(class CompoundTag &);
    /*269*/ virtual void __unk_vfn_269();
    /*277*/ virtual void _onSizeUpdated();
    /*278*/ virtual void __unk_vfn_278();
    /*280*/ virtual void spawnAnim();
    /*285*/ virtual float getSpeed() const;
    /*286*/ virtual void setSpeed(float);
    /*291*/ virtual void travel(float, float, float);
    /*292*/ virtual void travel(struct IMobMovementProxy &, float, float, float) const;
    /*294*/ virtual void aiStep();
    /*295*/ virtual void aiStep(struct IMobMovementProxy &) const;
    /*302*/ virtual int getItemUseDuration() const;
    /*303*/ virtual float getItemUseStartupProgress() const;
    /*304*/ virtual float getItemUseIntervalProgress() const;
    /*307*/ virtual void __unk_vfn_307();
    /*309*/ virtual bool isAlliedTo(class Mob *);
    /*311*/ virtual void __unk_vfn_311();
    /*321*/ virtual void sendArmorDamage(class std::bitset<4> const &);
    /*327*/ virtual std::vector<class ItemStack const *> getAllHand() const;
    /*328*/ virtual std::vector<class ItemStack const *> getAllEquipment() const;
    /*330*/ virtual void dropEquipmentOnDeath(class ActorDamageSource const &, int);
    /*331*/ virtual void dropEquipmentOnDeath();
    /*332*/ virtual void clearVanishEnchantedItemsOnDeath();
    /*333*/ virtual void sendInventory(bool);
    /*338*/ virtual void onBorn(class Actor &, class Actor &);
    /*343*/ virtual float _getWalkTargetValue(class BlockPos const &);
    /*344*/ virtual bool canExistWhenDisallowMob() const;
    /*345*/ virtual void __unk_vfn_345();
    /*350*/ virtual std::unique_ptr<class BodyControl> initBodyControl();
    /*351*/ virtual void jumpFromGround();
    /*352*/ virtual void jumpFromGround(struct IMobMovementProxy &) const;
    /*353*/ virtual void updateAi();
    /*355*/ virtual void _serverAiMobStep();
    /*358*/ virtual void updateGliding();
    /*359*/ virtual void __unk_vfn_359();
    /*361*/ virtual void prepareRegion(class ChunkSource &);
    /*362*/ virtual void destroyRegion();
    /*363*/ virtual void suspendRegion();
    /*364*/ virtual void resendAllChunks();
    /*365*/ virtual void _fireWillChangeDimension();
    /*366*/ virtual void _fireDimensionChanged();
    /*367*/ virtual void changeDimensionWithCredits(class AutomaticID<class Dimension, int>);
    /*368*/ virtual void tickWorld(struct Tick const &);
    /*369*/ virtual void __unk_vfn_369() = 0;
    /*370*/ virtual std::vector<class ChunkPos> const & getTickingOffsets() const;
    /*371*/ virtual void moveView();
    /*372*/ virtual void setName(std::string const &);
    /*373*/ virtual void checkMovementStats(class Vec3 const &);
    /*374*/ virtual void __unk_vfn_374();
    /*375*/ virtual void __unk_vfn_375();
    /*376*/ virtual void respawn();
    /*377*/ virtual void __unk_vfn_377();
    /*378*/ virtual void __unk_vfn_378();
    /*379*/ virtual bool hasResource(int);
    /*380*/ virtual void completeUsingItem();
    /*381*/ virtual void setPermissions(enum CommandPermissionLevel);
    /*382*/ virtual void startDestroying();
    /*383*/ virtual void stopDestroying();
    /*384*/ virtual void __unk_vfn_384();
    /*385*/ virtual void __unk_vfn_385();
    /*386*/ virtual void openTrading(struct ActorUniqueID const &, bool);
    /*387*/ virtual bool canOpenContainerScreen();
    /*388*/ virtual void __unk_vfn_388();
    /*389*/ virtual void __unk_vfn_389();
    /*390*/ virtual void openInventory();
    /*391*/ virtual void __unk_vfn_391();
    /*392*/ virtual void __unk_vfn_392();
    /*393*/ virtual void displayTextObjectMessage(class TextObjectRoot const &, std::string const &, std::string const &);
    /*394*/ virtual void displayTextObjectWhisperMessage(class ResolvedTextObject const &, std::string const &, std::string const &);
    /*395*/ virtual void displayWhisperMessage(std::string const &, std::string const &, std::string const &, std::string const &);
    /*396*/ virtual enum BedSleepingResult startSleepInBed(class BlockPos const &);
    /*397*/ virtual void stopSleepInBed(bool, bool);
    /*398*/ virtual bool canStartSleepInBed();
    /*399*/ virtual int getSleepTimer() const;
    /*400*/ virtual int getPreviousTickSleepTimer() const;
    /*401*/ virtual void __unk_vfn_401();
    /*402*/ virtual void __unk_vfn_402();
    /*403*/ virtual bool isHostingPlayer() const;
    /*404*/ virtual bool isLoading() const;
    /*405*/ virtual bool isPlayerInitialized() const;
    /*406*/ virtual void __unk_vfn_406();
    /*407*/ virtual void registerTrackedBoss(struct ActorUniqueID);
    /*408*/ virtual void unRegisterTrackedBoss(struct ActorUniqueID);
    /*409*/ virtual void setPlayerGameType(enum GameType);
    /*410*/ virtual void initHUDContainerManager();
    /*411*/ virtual void _crit(class Actor &);
    /*412*/ virtual class IMinecraftEventing * getEventing() const;
    /*413*/ virtual void __unk_vfn_413();
    /*414*/ virtual void sendEventPacket(class EventPacket &) const;
    /*415*/ virtual void addExperience(int);
    /*416*/ virtual void addLevels(int);
    /*417*/ virtual void setContainerData(class IContainerManager &, int, int) = 0;
    /*418*/ virtual void slotChanged(class IContainerManager &, class Container &, int, class ItemStack const &, class ItemStack const &, bool) = 0;
    /*419*/ virtual void inventoryChanged(class Container &, int, class ItemStack const &, class ItemStack const &, bool);
    /*420*/ virtual void refreshContainer(class IContainerManager &) = 0;
    /*421*/ virtual void deleteContainerManager();
    /*422*/ virtual void setFieldOfViewModifier(float);
    /*423*/ virtual bool is2DPositionRelevant(class AutomaticID<class Dimension, int>, class BlockPos const &);
    /*424*/ virtual bool isActorRelevant(class Actor const &);
    /*425*/ virtual bool isTeacher() const = 0;
    /*426*/ virtual void onSuspension();
    /*427*/ virtual void onLinkedSlotsChanged();
    /*428*/ virtual void startCooldown(class Item const *, bool);
    /*429*/ virtual int getItemCooldownLeft(class HashedString const &) const;
    /*430*/ virtual int getItemCooldownLeft(unsigned __int64) const;
    /*431*/ virtual int getMaxItemCooldownLeft() const;
    /*432*/ virtual bool isItemOnCooldown(class HashedString const &) const;
    /*433*/ virtual void sendInventoryTransaction(class InventoryTransaction const &) const = 0;
    /*434*/ virtual void sendComplexInventoryTransaction(std::unique_ptr<class ComplexInventoryTransaction>) const = 0;
    /*435*/ virtual void sendNetworkPacket(class Packet &) const;
    /*436*/ virtual class PlayerEventCoordinator & getPlayerEventCoordinator() = 0;
    /*437*/ virtual class MoveInputHandler * getMoveInputHandler() const = 0;
    /*438*/ virtual enum InputMode getInputMode() const = 0;
    /*439*/ virtual enum ClientPlayMode getPlayMode() const = 0;
    /*440*/ virtual void reportMovementTelemetry(enum MovementEventType);
    /*441*/ virtual void __unk_vfn_441();
    /*442*/ virtual std::string getXuid() const;
    /*443*/ virtual struct PlayerMovementSettings const & getMovementSettings() const;
    /*444*/ virtual void onMovePlayerPacketNormal(class Vec3 const &, class Vec2 const &, float);
    /*445*/ virtual class std::shared_ptr<class ChunkViewSource> _createChunkSource(class ChunkSource &);
    /*
    inline enum StructureFeatureType getCurrentStructureFeature() const{
        enum StructureFeatureType (Player::*rv)() const;
        *((void**)&rv) = dlsym("?getCurrentStructureFeature@Player@@UEBA?AW4StructureFeatureType@@XZ");
        return (this->*rv)();
    }
    inline bool isInTrialMode(){
        bool (Player::*rv)();
        *((void**)&rv) = dlsym("?isInTrialMode@Player@@UEAA_NXZ");
        return (this->*rv)();
    }
    inline bool useNewAi() const{
        bool (Player::*rv)() const;
        *((void**)&rv) = dlsym("?useNewAi@Player@@UEBA_NXZ");
        return (this->*rv)();
    }
    inline bool isSimulated() const{
        bool (Player::*rv)() const;
        *((void**)&rv) = dlsym("?isSimulated@Player@@UEBA_NXZ");
        return (this->*rv)();
    }
    inline bool isLocalPlayer() const{
        bool (Player::*rv)() const;
        *((void**)&rv) = dlsym("?isLocalPlayer@Player@@UEBA_NXZ");
        return (this->*rv)();
    }
    inline unsigned int getUserId() const{
        unsigned int (Player::*rv)() const;
        *((void**)&rv) = dlsym("?getUserId@Player@@UEBAIXZ");
        return (this->*rv)();
    }
    inline bool isPlayer() const{
        bool (Player::*rv)() const;
        *((void**)&rv) = dlsym("?isPlayer@Player@@UEBA_NXZ");
        return (this->*rv)();
    }
    inline bool isCreativeModeAllowed(){
        bool (Player::*rv)();
        *((void**)&rv) = dlsym("?isCreativeModeAllowed@Player@@UEAA_NXZ");
        return (this->*rv)();
    }
    inline bool isAutoJumpEnabled() const{
        bool (Player::*rv)() const;
        *((void**)&rv) = dlsym("?isAutoJumpEnabled@Player@@UEBA_NXZ");
        return (this->*rv)();
    }
    inline bool isShootable(){
        bool (Player::*rv)();
        *((void**)&rv) = dlsym("?isShootable@Player@@UEAA_NXZ");
        return (this->*rv)();
    }
    inline bool getAlwaysShowNameTag() const{
        bool (Player::*rv)() const;
        *((void**)&rv) = dlsym("?getAlwaysShowNameTag@Player@@UEBA_NXZ");
        return (this->*rv)();
    }
    inline void displayChatMessage(std::string const & a0, std::string const & a1){
        void (Player::*rv)(std::string const &, std::string const &);
        *((void**)&rv) = dlsym("?displayChatMessage@Player@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z");
        return (this->*rv)(std::forward<std::string const &>(a0), std::forward<std::string const &>(a1));
    }
    inline void openChalkboard(class ChalkboardBlockActor & a0, bool a1){
        void (Player::*rv)(class ChalkboardBlockActor &, bool);
        *((void**)&rv) = dlsym("?openChalkboard@Player@@UEAAXAEAVChalkboardBlockActor@@_N@Z");
        return (this->*rv)(std::forward<class ChalkboardBlockActor &>(a0), std::forward<bool>(a1));
    }
    inline void openBook(int a0, bool a1, int a2, class BlockActor * a3){
        void (Player::*rv)(int, bool, int, class BlockActor *);
        *((void**)&rv) = dlsym("?openBook@Player@@UEAAXH_NHPEAVBlockActor@@@Z");
        return (this->*rv)(std::forward<int>(a0), std::forward<bool>(a1), std::forward<int>(a2), std::forward<class BlockActor *>(a3));
    }
    inline void displayClientMessage(std::string const & a0){
        void (Player::*rv)(std::string const &);
        *((void**)&rv) = dlsym("?displayClientMessage@Player@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z");
        return (this->*rv)(std::forward<std::string const &>(a0));
    }
    inline void openSign(class BlockPos const & a0){
        void (Player::*rv)(class BlockPos const &);
        *((void**)&rv) = dlsym("?openSign@Player@@UEAAXAEBVBlockPos@@@Z");
        return (this->*rv)(std::forward<class BlockPos const &>(a0));
    }
    inline void playEmote(std::string const & a0){
        void (Player::*rv)(std::string const &);
        *((void**)&rv) = dlsym("?playEmote@Player@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z");
        return (this->*rv)(std::forward<std::string const &>(a0));
    }
    inline void _serverInitItemStackIds(){
        void (Player::*rv)();
        *((void**)&rv) = dlsym("?_serverInitItemStackIds@Player@@MEAAXXZ");
        return (this->*rv)();
    }
    inline void openPortfolio(){
        void (Player::*rv)();
        *((void**)&rv) = dlsym("?openPortfolio@Player@@UEAAXXZ");
        return (this->*rv)();
    }
    inline void resetRot(){
        void (Player::*rv)();
        *((void**)&rv) = dlsym("?resetRot@Player@@UEAAXXZ");
        return (this->*rv)();
    }
    inline void stopLoading(){
        void (Player::*rv)();
        *((void**)&rv) = dlsym("?stopLoading@Player@@UEAAXXZ");
        return (this->*rv)();
    }
    inline void openNpcInteractScreen(class std::shared_ptr<struct INpcDialogueData> a0){
        void (Player::*rv)(class std::shared_ptr<struct INpcDialogueData>);
        *((void**)&rv) = dlsym("?openNpcInteractScreen@Player@@UEAAXV?$shared_ptr@UINpcDialogueData@@@std@@@Z");
        return (this->*rv)(std::forward<class std::shared_ptr<struct INpcDialogueData>>(a0));
    }
    inline  ~Player(){
         (Player::*rv)();
        *((void**)&rv) = dlsym("??1Player@@UEAA@XZ");
        return (this->*rv)();
    }
    */
    MCAPI Player(class Level &, class PacketSender &, enum GameType, class NetworkIdentifier const &, unsigned char, class mce::UUID, std::string const &, std::unique_ptr<class Certificate>, class EntityContext &, std::string const &, std::string const &);
    MCAPI void applyExhaustion(class Vec3 const &);
    MCAPI void broadcastPlayerSpawnedMobEvent(enum ActorType, enum MobSpawnMethod);
    MCAPI bool canBeSeenOnMap() const;
    MCAPI bool canDestroy(class Block const &) const;
    MCAPI bool canUseAbility(enum AbilitiesIndex) const;
    MCAPI bool canUseOperatorBlocks() const;
    MCAPI void causeFoodExhaustion(float);
    MCAPI void clearRespawnPosition();
    MCAPI void eat(class ItemStack const &);
    MCAPI void eat(int, float);
    MCAPI bool equippedArmorItemCanBeMoved(class ItemStack const &) const;
    MCAPI void fireDimensionChangedEvent(class AutomaticID<class Dimension, int>);
    MCAPI bool forceAllowEating() const;
    MCAPI class Agent * getAgent() const;
    MCAPI struct ActorUniqueID getAgentID() const;
    MCAPI class Agent * getAgentIfAllowed(bool, struct ActorUniqueID) const;
    MCAPI class BlockPos const & getBedPosition() const;
    MCAPI __int64 getBlockedUsingDamagedShieldTimeStamp() const;
    MCAPI __int64 getBlockedUsingShieldTimeStamp() const;
    MCAPI __int64 getBlockingStartTimeStamp() const;
    MCAPI class Vec3 getCapePos(float);
    MCAPI class std::weak_ptr<class IContainerManager> getContainerManager();
    MCAPI class ItemStack const & getCurrentActiveShield() const;
    MCAPI float getDestroyProgress(class Block const &) const;
    MCAPI float getDestroySpeed(class Block const &) const;
    MCAPI int getDirection() const;
    MCAPI int getEnchantmentSeed() const;
    MCAPI class AutomaticID<class Dimension, int> getExpectedSpawnDimensionId() const;
    MCAPI class BlockPos const & getExpectedSpawnPosition() const;
    MCAPI std::string getInteractText() const;
    MCAPI class Container & getInventory();
    MCAPI class ItemStack const & getItemInUse() const;
    MCAPI std::string getItemInteractText(class Item const &) const;
    MCAPI class ItemStackNetManagerBase * getItemStackNetManager();
    MCAPI class ItemStackNetManagerBase const * getItemStackNetManager() const;
    MCAPI float getLuck();
    MCAPI int getMapIndex();
    MCAPI void getNewEnchantmentSeed();
    MCAPI class AABB getPickupArea() const;
    MCAPI enum BuildPlatform getPlatform() const;
    MCAPI std::string const & getPlatformOnlineId() const;
    MCAPI enum GameType getPlayerGameType() const;
    MCAPI int getPlayerIndex() const;
    MCAPI int getPlayerLevel() const;
    MCAPI enum PlayerPermissionLevel getPlayerPermissionLevel() const;
    MCAPI std::string const & getPlayerSessionId() const;
    MCAPI class ItemStack const & getPlayerUIItem(enum PlayerUISlot);
    MCAPI class BlockPos const & getRespawnAnchorPosition() const;
    MCAPI class ItemStack const & getSelectedItem() const;
    MCAPI int getSelectedItemSlot() const;
    MCAPI class SerializedSkin & getSkin();
    MCAPI class SerializedSkin const & getSkin() const;
    MCAPI float getSleepRotation() const;
    MCAPI class AutomaticID<class Dimension, int> getSpawnDimension() const;
    MCAPI class BlockPos const & getSpawnPosition() const;
    MCAPI class PlayerInventory & getSupplies();
    MCAPI class PlayerInventory const & getSupplies() const;
    MCAPI std::vector<struct ActorUniqueID> const & getTrackedBosses();
    MCAPI enum GameType getUnmappedPlayerGameType() const;
    MCAPI bool getUsedPotion();
    MCAPI int getXpNeededForNextLevel() const;
    MCAPI bool hasBedPosition() const;
    MCAPI bool hasOpenContainer() const;
    MCAPI bool hasOpenContainerOfContainerType(enum ContainerType) const;
    MCAPI bool hasOwnedChunkSource() const;
    MCAPI bool hasResource(class ItemDescriptor const &);
    MCAPI bool hasRespawnAnchorPosition() const;
    MCAPI bool hasRespawnPosition() const;
    MCAPI bool interact(class Actor &, class Vec3 const &);
    MCAPI bool isBouncing() const;
    MCAPI bool isForcedRespawn() const;
    MCAPI bool isHiddenFrom(class Mob &) const;
    MCAPI bool isHungry() const;
    MCAPI bool isHurt();
    MCAPI bool isInCreativeMode() const;
    MCAPI bool isInRaid() const;
    MCAPI bool isRespawningFromTheEnd() const;
    MCAPI bool isSleepingLongEnough() const;
    MCAPI bool isSpawned() const;
    MCAPI bool isUsingItem() const;
    MCAPI void moveSpawnView(class Vec3 const &, class AutomaticID<class Dimension, int>);
    MCAPI void recheckSpawnPosition();
    MCAPI void releaseUsingItem();
    MCAPI void resetPlayerLevel();
    MCAPI void resetToDefaultGameMode();
    MCAPI void setAgent(class Agent *);
    MCAPI void setAllPlayersSleeping();
    MCAPI void setBedRespawnPosition(class BlockPos const &);
    MCAPI void setBlockRespawnUntilClientMessage(bool);
    MCAPI void setChunkRadius(unsigned int);
    MCAPI void setContainerManager(class std::shared_ptr<class IContainerManager>);
    MCAPI void setCursorSelectedItem(class ItemStack const &);
    MCAPI void setCursorSelectedItemGroup(class ItemGroup const &);
    MCAPI void setEnchantmentSeed(int);
    MCAPI void setHasSeenCredits(bool);
    MCAPI void setMapIndex(int);
    MCAPI void setPlatformOnlineId(std::string const &);
    MCAPI void setPlayerIndex(int);
    MCAPI void setPlayerUIItem(enum PlayerUISlot, class ItemStack const &);
    MCAPI void setRespawnPosition(class BlockPos const &, class AutomaticID<class Dimension, int>);
    MCAPI void setRespawnPositionCandidate();
    MCAPI void setRespawnReady(class Vec3 const &);
    MCAPI void setSelectedItem(class ItemStack const &);
    MCAPI class ItemStack const & setSelectedSlot(int);
    MCAPI void setSpawnBlockRespawnPosition(class BlockPos const &, class AutomaticID<class Dimension, int>);
    MCAPI void setUsedPotion(bool);
    MCAPI bool shouldShowCredits() const;
    MCAPI void spawnExperienceOrb(class Vec3 const &, int);
    MCAPI void startCooldown(class HashedString const &, int, bool);
    MCAPI void startGliding();
    MCAPI void startUsingItem(class ItemStack const &, int);
    MCAPI void stopGliding();
    MCAPI void stopUsingItem();
    MCAPI bool take(class Actor &, int, int);
    MCAPI void updateInventoryTransactions();
    MCAPI void updateSkin(class SerializedSkin const &, int);
    MCAPI void updateSpawnChunkView();
    MCAPI void updateTrackedBosses();
    MCAPI void useSelectedItem(enum ItemUseMethod, bool);
    MCAPI static float const DEFAULT_BB_HEIGHT;
    MCAPI static float const DEFAULT_BB_WIDTH;
    MCAPI static float const DEFAULT_FLY_SPEED;
    MCAPI static float const DEFAULT_PLAYER_HEIGHT_OFFSET;
    MCAPI static float const DEFAULT_WALK_SPEED;
    MCAPI static float const DISTANCE_TO_TRANSFORM_EVENT;
    MCAPI static float const DISTANCE_TO_TRAVELLED_EVENT;
    MCAPI static class Attribute const EXHAUSTION;
    MCAPI static class Attribute const EXPERIENCE;
    MCAPI static int const GLIDE_STOP_DELAY;
    MCAPI static class Attribute const HUNGER;
    MCAPI static int const ITEM_USE_INTERVAL_DURATION;
    MCAPI static class Attribute const LEVEL;
    MCAPI static int const MAX_ITEM_USE_DURATION;
    MCAPI static float const PLAYER_ALIVE_HEIGHT;
    MCAPI static float const PLAYER_ALIVE_WIDTH;
    MCAPI static float const PLAYER_DEAD_HEIGHT;
    MCAPI static float const PLAYER_DEAD_WIDTH;
    MCAPI static float const PLAYER_DOWN_SWIM_SPEED;
    MCAPI static float const PLAYER_GLIDING_CAMERA_OFFSET;
    MCAPI static float const PLAYER_SLEEPING_CAMERA_OFFSET;
    MCAPI static float const PLAYER_SLEEPING_HEIGHT;
    MCAPI static float const PLAYER_SLEEPING_WIDTH;
    MCAPI static float const PLAYER_SNEAK_OFFSET;
    MCAPI static float const PLAYER_SWIMMING_CAMERA_OFFSET;
    MCAPI static float const PLAYER_SWIM_BREACH_ANGLE;
    MCAPI static float const PLAYER_SWIM_ENTER_THRESHOLD;
    MCAPI static float const PLAYER_SWIM_FLY_MULTI;
    MCAPI static float const PLAYER_UP_SWIM_SPEED;
    MCAPI static class Attribute const SATURATION;
    MCAPI static unsigned int const SPAWN_CHUNK_LARGE_JUMP;
    MCAPI static unsigned int const SPAWN_CHUNK_RADIUS;
    MCAPI static void _aiStep(struct IPlayerMovementProxy &);
    MCAPI static void _travel(struct IPlayerMovementProxy &, float, float, float);
    MCAPI static bool canJump(struct IPlayerMovementProxy &);
    MCAPI static bool checkAndFixSpawnPosition(class Vec3 &, std::vector<class gsl::not_null<class BlockSource *>>, class AABB, bool, bool, bool, bool, bool, bool, short);
    MCAPI static bool checkNeedAutoJump(struct IPlayerMovementProxy *, float, float);
    MCAPI static void goDownInWater(struct IActorMovementProxy &);
    MCAPI static void handleJumpEffects(struct IPlayerMovementProxy &);
    MCAPI static class Player * tryGetFromComponent(class FlagComponent<struct PlayerComponentFlag> const &, class ActorOwnerComponent &, bool);
    MCAPI static class Player * tryGetFromEntity(class EntityContext &, bool);
    MCAPI static class Player * tryGetFromEntity(class StackRefResultT<struct EntityRefTraits>, bool);

protected:
    MCAPI bool _checkAndFixSpawnPosition(class Vec3 &, std::vector<class gsl::not_null<class BlockSource *>>, bool, bool, bool, bool, bool) const;
    MCAPI void _chooseSpawnArea();
    MCAPI bool _chooseSpawnPositionWithinArea();
    MCAPI void _registerPlayerAttributes();
    MCAPI void _updateInteraction();
    MCAPI bool _validateSpawnPositionAvailability(class Vec3 const &, class BlockSource *, class Vec3 const *const) const;
    MCAPI bool checkBed(class BlockSource *, class Vec3 const *const);
    MCAPI bool checkSpawnBlock(class BlockSource const &) const;
    MCAPI static bool _isDangerousBlock(class Block const &, bool);

private:
    MCAPI void _addLevels(int);
    MCAPI bool _blockUsingShield(class ActorDamageSource const &, float);
    MCAPI void _ensureSafeSpawnPosition(class Vec3 &);
    MCAPI bool _findFallbackSpawnPosition(class Vec3 &, std::vector<class gsl::not_null<class BlockSource *>>, unsigned int);
    MCAPI void _handleCarriedItemInteractText();
    MCAPI bool _isChunkSourceLoaded(class Vec3 const &, class BlockSource const &) const;
    MCAPI void _registerElytraLoopSound();
    MCAPI void _sendShieldUpdatePacket(class ShieldItem const &, class ItemStack const &, class ItemStack const &, enum ContainerID, int);

};