all: bin/ MKIA

MKIA: bin/Game.o bin/main.o bin/Map.o bin/Card.o bin/Deck.o bin/Wound.o bin/ACColdToughness.o bin/ACConcentration.o bin/ACCrystallize.o bin/ACDetermination.o bin/ACInstinct.o bin/ACManaDraw.o bin/ACMarch.o bin/ACPromise.o bin/ACRage.o bin/ACStamina.o bin/ACSwiftness.o bin/ACThreaten.o bin/ACTranquility.o bin/ACAgility.o bin/ACBloodRage.o bin/ACCrushingBolt.o bin/ACFireBolt.o bin/ACFrostBridge.o bin/ACIceBolt.o bin/ACIceShield.o bin/ACIntimidate.o bin/ACPathFinding.o bin/ACRefreshingWalk.o bin/ACSongOfWind.o bin/ACSwiftBolt.o bin/BotPlayer.o bin/HumanPlayer.o bin/Skill.o bin/ColdSwordsmanship.o bin/DoubleTime.o bin/IDontGiveADamn.o bin/IFeelNoPain.o bin/ManaOverload.o bin/NightSharpshooting.o bin/ResistanceBreak.o bin/ShieldMastery.o bin/TvkMotivation.o bin/WhoNeedsMagic.o bin/UserInterface.o bin/UbuntuUI.o bin/WindowsUI.o bin/UAltemGuardians.o bin/UAltemMages.o bin/UAmotepFreezers.o bin/UAmotepGunners.o bin/UCatapults.o bin/UDelphanaMasters.o bin/UFireGolems.o bin/UFireMages.o bin/UForesters.o bin/UGuardianGolems.o bin/UHerbalists.o bin/UHeroesBlue.o bin/UHeroesGreen.o bin/UHeroesRed.o bin/UHeroesWhite.o bin/UIceGolems.o bin/UIceMages.o bin/UIllusionists.o bin/UMagicFamiliars.o bin/Unit.o bin/UNorthernMonks.o bin/USavageMonks.o bin/UPeasants.o bin/URedCapeMonks.o bin/UScouts.o bin/UShockTroops.o bin/USorcerers.o bin/UThugs.o bin/UUtemGuardsmen.o bin/UUtemCrossbowmen.o bin/UUtemSwordsmen.o
	g++ -std=c++14 -O2 -o MKIA bin/*.o -Wall

bin/Game.o: src/Game.cpp
	g++ -std=c++14 -O2 -o bin/Game.o -c src/Game.cpp -Wall

bin/main.o: src/main.cpp
	g++ -std=c++14 -O2 -o bin/main.o -c src/main.cpp -Wall

bin/Map.o: src/Map.cpp
	g++ -std=c++14 -O2 -o bin/Map.o -c src/Map.cpp -Wall

bin/Card.o: src/Cards/Card.cpp
	g++ -std=c++14 -O2 -o bin/Card.o -c src/Cards/Card.cpp -Wall

bin/Deck.o: src/Cards/Deck.cpp
	g++ -std=c++14 -O2 -o bin/Deck.o -c src/Cards/Deck.cpp -Wall

bin/Wound.o: src/Cards/Wound.cpp
	g++ -std=c++14 -O2 -o bin/Wound.o -c src/Cards/Wound.cpp -Wall

bin/ACColdToughness.o: src/Cards/ActionCards/ACColdToughness.cpp
	g++ -std=c++14 -O2 -o bin/ACColdToughness.o -c src/Cards/ActionCards/ACColdToughness.cpp -Wall

bin/ACConcentration.o: src/Cards/ActionCards/ACConcentration.cpp
	g++ -std=c++14 -O2 -o bin/ACConcentration.o -c src/Cards/ActionCards/ACConcentration.cpp -Wall

bin/ACCrystallize.o: src/Cards/ActionCards/ACCrystallize.cpp
	g++ -std=c++14 -O2 -o bin/ACCrystallize.o -c src/Cards/ActionCards/ACCrystallize.cpp -Wall

bin/ACDetermination.o: src/Cards/ActionCards/ACDetermination.cpp
	g++ -std=c++14 -O2 -o bin/ACDetermination.o -c src/Cards/ActionCards/ACDetermination.cpp -Wall

bin/ACInstinct.o: src/Cards/ActionCards/ACInstinct.cpp
	g++ -std=c++14 -O2 -o bin/ACInstinct.o -c src/Cards/ActionCards/ACInstinct.cpp -Wall

bin/ACManaDraw.o: src/Cards/ActionCards/ACManaDraw.cpp
	g++ -std=c++14 -O2 -o bin/ACManaDraw.o -c src/Cards/ActionCards/ACManaDraw.cpp -Wall

bin/ACMarch.o: src/Cards/ActionCards/ACMarch.cpp
	g++ -std=c++14 -O2 -o bin/ACMarch.o -c src/Cards/ActionCards/ACMarch.cpp -Wall

bin/ACPromise.o: src/Cards/ActionCards/ACPromise.cpp
	g++ -std=c++14 -O2 -o bin/ACPromise.o -c src/Cards/ActionCards/ACPromise.cpp -Wall

bin/ACRage.o: src/Cards/ActionCards/ACRage.cpp
	g++ -std=c++14 -O2 -o bin/ACRage.o -c src/Cards/ActionCards/ACRage.cpp -Wall

bin/ACStamina.o: src/Cards/ActionCards/ACStamina.cpp
	g++ -std=c++14 -O2 -o bin/ACStamina.o -c src/Cards/ActionCards/ACStamina.cpp -Wall

bin/ACSwiftness.o: src/Cards/ActionCards/ACSwiftness.cpp
	g++ -std=c++14 -O2 -o bin/ACSwiftness.o -c src/Cards/ActionCards/ACSwiftness.cpp -Wall

bin/ACThreaten.o: src/Cards/ActionCards/ACThreaten.cpp
	g++ -std=c++14 -O2 -o bin/ACThreaten.o -c src/Cards/ActionCards/ACThreaten.cpp -Wall

bin/ACTranquility.o: src/Cards/ActionCards/ACTranquility.cpp
	g++ -std=c++14 -O2 -o bin/ACTranquility.o -c src/Cards/ActionCards/ACTranquility.cpp -Wall

bin/ACAgility.o: src/Cards/ActionCards/Advanced/ACAgility.cpp
	g++ -std=c++14 -O2 -o bin/ACAgility.o -c src/Cards/ActionCards/Advanced/ACAgility.cpp -Wall

bin/ACBloodRage.o: src/Cards/ActionCards/Advanced/ACBloodRage.cpp
	g++ -std=c++14 -O2 -o bin/ACBloodRage.o -c src/Cards/ActionCards/Advanced/ACBloodRage.cpp -Wall

bin/ACCrushingBolt.o: src/Cards/ActionCards/Advanced/ACCrushingBolt.cpp
	g++ -std=c++14 -O2 -o bin/ACCrushingBolt.o -c src/Cards/ActionCards/Advanced/ACCrushingBolt.cpp -Wall

bin/ACFireBolt.o: src/Cards/ActionCards/Advanced/ACFireBolt.cpp
	g++ -std=c++14 -O2 -o bin/ACFireBolt.o -c src/Cards/ActionCards/Advanced/ACFireBolt.cpp -Wall

bin/ACFrostBridge.o: src/Cards/ActionCards/Advanced/ACFrostBridge.cpp
	g++ -std=c++14 -O2 -o bin/ACFrostBridge.o -c src/Cards/ActionCards/Advanced/ACFrostBridge.cpp -Wall

bin/ACIceBolt.o: src/Cards/ActionCards/Advanced/ACIceBolt.cpp
	g++ -std=c++14 -O2 -o bin/ACIceBolt.o -c src/Cards/ActionCards/Advanced/ACIceBolt.cpp -Wall

bin/ACIceShield.o: src/Cards/ActionCards/Advanced/ACIceShield.cpp
	g++ -std=c++14 -O2 -o bin/ACIceShield.o -c src/Cards/ActionCards/Advanced/ACIceShield.cpp -Wall

bin/ACIntimidate.o: src/Cards/ActionCards/Advanced/ACIntimidate.cpp
	g++ -std=c++14 -O2 -o bin/ACIntimidate.o -c src/Cards/ActionCards/Advanced/ACIntimidate.cpp -Wall

bin/ACPathFinding.o: src/Cards/ActionCards/Advanced/ACPathFinding.cpp
	g++ -std=c++14 -O2 -o bin/ACPathFinding.o -c src/Cards/ActionCards/Advanced/ACPathFinding.cpp -Wall

bin/ACRefreshingWalk.o: src/Cards/ActionCards/Advanced/ACRefreshingWalk.cpp
	g++ -std=c++14 -O2 -o bin/ACRefreshingWalk.o -c src/Cards/ActionCards/Advanced/ACRefreshingWalk.cpp -Wall

bin/ACSongOfWind.o: src/Cards/ActionCards/Advanced/ACSongOfWind.cpp
	g++ -std=c++14 -O2 -o bin/ACSongOfWind.o -c src/Cards/ActionCards/Advanced/ACSongOfWind.cpp -Wall

bin/ACSwiftBolt.o: src/Cards/ActionCards/Advanced/ACSwiftBolt.cpp
	g++ -std=c++14 -O2 -o bin/ACSwiftBolt.o -c src/Cards/ActionCards/Advanced/ACSwiftBolt.cpp -Wall

bin/BotPlayer.o: src/Player/BotPlayer.cpp
	g++ -std=c++14 -O2 -o bin/BotPlayer.o -c src/Player/BotPlayer.cpp -Wall

bin/HumanPlayer.o: src/Player/HumanPlayer.cpp
	g++ -std=c++14 -O2 -o bin/HumanPlayer.o -c src/Player/HumanPlayer.cpp -Wall

bin/Skill.o: src/Skills/Skill.cpp
	g++ -std=c++14 -O2 -o bin/Skill.o -c src/Skills/Skill.cpp -Wall

bin/ColdSwordsmanship.o: src/Skills/Tovak/ColdSwordsmanship.cpp
	g++ -std=c++14 -O2 -o bin/ColdSwordsmanship.o -c src/Skills/Tovak/ColdSwordsmanship.cpp -Wall

bin/DoubleTime.o: src/Skills/Tovak/DoubleTime.cpp
	g++ -std=c++14 -O2 -o bin/DoubleTime.o -c src/Skills/Tovak/DoubleTime.cpp -Wall

bin/IDontGiveADamn.o: src/Skills/Tovak/IDontGiveADamn.cpp
	g++ -std=c++14 -O2 -o bin/IDontGiveADamn.o -c src/Skills/Tovak/IDontGiveADamn.cpp -Wall

bin/IFeelNoPain.o: src/Skills/Tovak/IFeelNoPain.cpp
	g++ -std=c++14 -O2 -o bin/IFeelNoPain.o -c src/Skills/Tovak/IFeelNoPain.cpp -Wall

bin/ManaOverload.o: src/Skills/Tovak/ManaOverload.cpp
	g++ -std=c++14 -O2 -o bin/ManaOverload.o -c src/Skills/Tovak/ManaOverload.cpp -Wall

bin/NightSharpshooting.o: src/Skills/Tovak/NightSharpshooting.cpp
	g++ -std=c++14 -O2 -o bin/NightSharpshooting.o -c src/Skills/Tovak/NightSharpshooting.cpp -Wall

bin/ResistanceBreak.o: src/Skills/Tovak/ResistanceBreak.cpp
	g++ -std=c++14 -O2 -o bin/ResistanceBreak.o -c src/Skills/Tovak/ResistanceBreak.cpp -Wall

bin/ShieldMastery.o: src/Skills/Tovak/ShieldMastery.cpp
	g++ -std=c++14 -O2 -o bin/ShieldMastery.o -c src/Skills/Tovak/ShieldMastery.cpp -Wall

bin/TvkMotivation.o: src/Skills/Tovak/TvkMotivation.cpp
	g++ -std=c++14 -O2 -o bin/TvkMotivation.o -c src/Skills/Tovak/TvkMotivation.cpp -Wall

bin/WhoNeedsMagic.o: src/Skills/Tovak/WhoNeedsMagic.cpp
	g++ -std=c++14 -O2 -o bin/WhoNeedsMagic.o -c src/Skills/Tovak/WhoNeedsMagic.cpp -Wall

bin/UserInterface.o: src/UserInterface/UserInterface.cpp
	g++ -std=c++14 -O2 -o bin/UserInterface.o -c src/UserInterface/UserInterface.cpp -Wall

bin/UbuntuUI.o: src/UserInterface/UbuntuUI.cpp
	g++ -std=c++14 -O2 -o bin/UbuntuUI.o -c src/UserInterface/UbuntuUI.cpp -Wall

bin/WindowsUI.o: src/UserInterface/WindowsUI.cpp
	g++ -std=c++14 -O2 -o bin/WindowsUI.o -c src/UserInterface/WindowsUI.cpp -Wall

bin/UAltemGuardians.o: src/Units/UAltemGuardians.cpp
	g++ -std=c++14 -O2 -o bin/UAltemGuardians.o -c src/Units/UAltemGuardians.cpp -Wall

bin/UAltemMages.o: src/Units/UAltemMages.cpp
	g++ -std=c++14 -O2 -o bin/UAltemMages.o -c src/Units/UAltemMages.cpp -Wall

bin/UAmotepFreezers.o: src/Units/UAmotepFreezers.cpp
	g++ -std=c++14 -O2 -o bin/UAmotepFreezers.o -c src/Units/UAmotepFreezers.cpp -Wall

bin/UAmotepGunners.o: src/Units/UAmotepGunners.cpp
	g++ -std=c++14 -O2 -o bin/UAmotepGunners.o -c src/Units/UAmotepGunners.cpp -Wall

bin/UCatapults.o: src/Units/UCatapults.cpp
	g++ -std=c++14 -O2 -o bin/UCatapults.o -c src/Units/UCatapults.cpp -Wall

bin/UDelphanaMasters.o: src/Units/UDelphanaMasters.cpp
	g++ -std=c++14 -O2 -o bin/UDelphanaMasters.o -c src/Units/UDelphanaMasters.cpp -Wall

bin/UFireGolems.o: src/Units/UFireGolems.cpp
	g++ -std=c++14 -O2 -o bin/UFireGolems.o -c src/Units/UFireGolems.cpp -Wall

bin/UFireMages.o: src/Units/UFireMages.cpp
	g++ -std=c++14 -O2 -o bin/UFireMages.o -c src/Units/UFireMages.cpp -Wall

bin/UForesters.o: src/Units/UForesters.cpp
	g++ -std=c++14 -O2 -o bin/UForesters.o -c src/Units/UForesters.cpp -Wall

bin/UGuardianGolems.o: src/Units/UGuardianGolems.cpp
	g++ -std=c++14 -O2 -o bin/UGuardianGolems.o -c src/Units/UGuardianGolems.cpp -Wall

bin/UHerbalists.o: src/Units/UHerbalists.cpp
	g++ -std=c++14 -O2 -o bin/UHerbalists.o -c src/Units/UHerbalists.cpp -Wall

bin/UHeroesBlue.o: src/Units/UHeroesBlue.cpp
	g++ -std=c++14 -O2 -o bin/UHeroesBlue.o -c src/Units/UHeroesBlue.cpp -Wall

bin/UHeroesGreen.o: src/Units/UHeroesGreen.cpp
	g++ -std=c++14 -O2 -o bin/UHeroesGreen.o -c src/Units/UHeroesGreen.cpp -Wall

bin/UHeroesRed.o: src/Units/UHeroesRed.cpp
	g++ -std=c++14 -O2 -o bin/UHeroesRed.o -c src/Units/UHeroesRed.cpp -Wall

bin/UHeroesWhite.o: src/Units/UHeroesWhite.cpp
	g++ -std=c++14 -O2 -o bin/UHeroesWhite.o -c src/Units/UHeroesWhite.cpp -Wall

bin/UIceGolems.o: src/Units/UIceGolems.cpp
	g++ -std=c++14 -O2 -o bin/UIceGolems.o -c src/Units/UIceGolems.cpp -Wall

bin/UIceMages.o: src/Units/UIceMages.cpp
	g++ -std=c++14 -O2 -o bin/UIceMages.o -c src/Units/UIceMages.cpp -Wall

bin/UIllusionists.o: src/Units/UIllusionists.cpp
	g++ -std=c++14 -O2 -o bin/UIllusionists.o -c src/Units/UIllusionists.cpp -Wall

bin/UMagicFamiliars.o: src/Units/UMagicFamiliars.cpp
	g++ -std=c++14 -O2 -o bin/UMagicFamiliars.o -c src/Units/UMagicFamiliars.cpp -Wall

bin/Unit.o: src/Units/Unit.cpp
	g++ -std=c++14 -O2 -o bin/Unit.o -c src/Units/Unit.cpp -Wall

bin/UNorthernMonks.o: src/Units/UNorthernMonks.cpp
	g++ -std=c++14 -O2 -o bin/UNorthernMonks.o -c src/Units/UNorthernMonks.cpp -Wall

bin/UPeasants.o: src/Units/UPeasants.cpp
	g++ -std=c++14 -O2 -o bin/UPeasants.o -c src/Units/UPeasants.cpp -Wall

bin/URedCapeMonks.o: src/Units/URedCapeMonks.cpp
	g++ -std=c++14 -O2 -o bin/URedCapeMonks.o -c src/Units/URedCapeMonks.cpp -Wall

bin/USavageMonks.o: src/Units/USavageMonks.cpp
	g++ -std=c++14 -O2 -o bin/USavageMonks.o -c src/Units/USavageMonks.cpp -Wall

bin/UScouts.o: src/Units/UScouts.cpp
	g++ -std=c++14 -O2 -o bin/UScouts.o -c src/Units/UScouts.cpp -Wall

bin/UShockTroops.o: src/Units/UShockTroops.cpp
	g++ -std=c++14 -O2 -o bin/UShockTroops.o -c src/Units/UShockTroops.cpp -Wall

bin/USorcerers.o: src/Units/USorcerers.cpp
	g++ -std=c++14 -O2 -o bin/USorcerers.o -c src/Units/USorcerers.cpp -Wall

bin/UThugs.o: src/Units/UThugs.cpp
	g++ -std=c++14 -O2 -o bin/UThugs.o -c src/Units/UThugs.cpp -Wall

bin/UUtemCrossbowmen.o: src/Units/UUtemCrossbowmen.cpp
	g++ -std=c++14 -O2 -o bin/UUtemCrossbowmen.o -c src/Units/UUtemCrossbowmen.cpp -Wall

bin/UUtemGuardsmen.o: src/Units/UUtemGuardsmen.cpp
	g++ -std=c++14 -O2 -o bin/UUtemGuardsmen.o -c src/Units/UUtemGuardsmen.cpp -Wall

bin/UUtemSwordsmen.o: src/Units/UUtemSwordsmen.cpp
	g++ -std=c++14 -O2 -o bin/UUtemSwordsmen.o -c src/Units/UUtemSwordsmen.cpp -Wall

bin/:
	mkdir -p bin

clean:
	rm -rf bin
	rm -f MKIA
