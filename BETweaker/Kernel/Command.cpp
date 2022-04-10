#include "../Global.h"
#include <RegCommandAPI.h>
#include "../Main/Module.h"
using namespace RegisterCommandHelper;

void BETweakerUpgradeCommand(CommandOutput& output, bool isForce)
{
    std::thread([isForce]() {
        // Set global SEH-Exception handler
        _set_se_translator(seh_exception::TranslateSEHtoCE);

        CheckAutoUpdate(true, isForce);
        }).detach();
}


class BETCommand : public Command
{

    enum class Operation
    {
        Upgrade,
		Reload,
        BetterHarvestingCrop,
        NoFarmDestroy,
        FastSleeping,
        HUBinfo,
        EditSign,
        DispenserCrops,
        FastLeafDecay,
        AutoFish,
        DoubleDoors,
        FastSetMinecart
    } operation;
    bool isenable;
    enum class UpgradeOption
    {
        Force
    }upgradeOption;
    bool hasUpgradeOption;
	
public:

    void execute(CommandOrigin const& ori, CommandOutput& output) const override
    {
        switch (operation)
        {
        case Operation::BetterHarvestingCrop:
            Settings::BetterHarvestingCrop = isenable;
            output.success(std::to_string(isenable));
            break;
        case Operation::NoFarmDestroy:
            Settings::NoFarmDestroy = isenable;
            output.success(std::to_string(isenable));
            break;
        case Operation::FastSleeping:
            Settings::FastSleeping = isenable;
            output.success(std::to_string(isenable));
            break;
        case Operation::HUBinfo:
            if (Settings::HUBinfo == isenable) break;
            Settings::HUBinfo = isenable;
            if (isenable)
                Module::HUBInfo();
            else
                hubinfo.cancel();
            break;
        case Operation::DispenserCrops:
            Settings::DispenserCrops = isenable;
            output.success(std::to_string(isenable));
            break;
        case Operation::EditSign:
            Settings::EditSign = isenable;
            output.success(std::to_string(isenable));
            break;
        case Operation::FastLeafDecay:
            Settings::FastLeafDecay = isenable;
            output.success(std::to_string(isenable));
            break;
        case Operation::AutoFish:
            Settings::AutoFish = isenable;
            output.success(std::to_string(isenable));
            break;
        case Operation::DoubleDoors:
            Settings::DoubleDoors = isenable;
            output.success(std::to_string(isenable));
            break;
        case Operation::FastSetMinecart:
            Settings::FastSetMinecart = isenable;
            output.success(std::to_string(isenable));
        case Operation::Reload:
            Settings::reloadJson(JsonFile);
            output.success("reload success");
            return;
        case Operation::Upgrade:
            BETweakerUpgradeCommand(output, hasUpgradeOption && upgradeOption == UpgradeOption::Force);
            return;
        }
        Settings::reloadJson(JsonFile);
    }

    static void setup(CommandRegistry* registry)
    {
        // Register Cmd
        registry->registerCommand("bet", "BETweaker System", CommandPermissionLevel::GameMasters, { (CommandFlagValue)1 }, { (CommandFlagValue)0x80 });

        registry->addEnum<Operation>("Function", {
            {"betterharvest", Operation::BetterHarvestingCrop},
            {"nofarmdestroy", Operation::NoFarmDestroy},
            {"fastsleep", Operation::FastSleeping},
            {"dispensercrops", Operation::DispenserCrops},
            {"hubinfo", Operation::HUBinfo},
            {"editsign", Operation::EditSign},
            {"fastleafdecay", Operation::FastLeafDecay},
            {"autofish", Operation::AutoFish},
            {"doubledoors", Operation::DoubleDoors},
            {"fastsetminecart", Operation::FastSetMinecart},
            }
        );
        registry->addEnum<Operation>("Operation_OptionalName", {
            {"reload", Operation::Reload},
            });
        registry->addEnum<Operation>("Operation_WithOption", {
            {"upgrade", Operation::Upgrade},
            });
        registry->addEnum<UpgradeOption>("UpgradeOption", { 
            {"force", UpgradeOption::Force} 
            });
		
        registry->registerOverload<BETCommand>(
            "bet",
            makeMandatory<CommandParameterDataType::ENUM>(&BETCommand::operation, "Operation", "Operation_WithOption").addOptions((CommandParameterOption)1),
            makeOptional<CommandParameterDataType::ENUM>(&BETCommand::upgradeOption, "Option", "UpgradeOption", &BETCommand::hasUpgradeOption).addOptions((CommandParameterOption)1));
		
        registry->registerOverload<BETCommand>(
            "bet",
            makeMandatory<CommandParameterDataType::ENUM>(&BETCommand::operation, "Operation", "Function"),
            makeMandatory(&BETCommand::isenable,"Enable"));

        registry->registerOverload<BETCommand>(
            "bet",
            makeMandatory<CommandParameterDataType::ENUM>(&BETCommand::operation, "Operation", "Operation_OptionalName").addOptions((CommandParameterOption)1));
		
    }
};

class SeedCommand : public Command
{

public:

    void execute(CommandOrigin const& ori, CommandOutput& output) const override
    {
        vector<CommandOutputParameter>opt;
        opt.push_back(CommandOutputParameter::CommandOutputParameter(std::to_string(Global<Level>->getSeed()), 0));
        output.success("commands.seed.success",opt);
    }

    static void setup(CommandRegistry* registry)
    {
        // Register Cmd
        registry->registerCommand("seed", "get level's seed", CommandPermissionLevel::GameMasters, { (CommandFlagValue)0 }, { (CommandFlagValue)0x80 });
        registry->registerOverload<SeedCommand>("seed");
    }
};

void RegisterCommands()
{
    Event::RegCmdEvent::subscribe([](Event::RegCmdEvent ev) { // Register commands
        BETCommand::setup(ev.mCommandRegistry);
        SeedCommand::setup(ev.mCommandRegistry);
        return true;
        });
}
