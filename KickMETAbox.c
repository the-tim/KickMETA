/*
	META - Motivational Electronic Text Advisor
	https://www.kickstarter.com/projects/the-tim/meta-the-idea-generator
	by Tim Ellis (@The_Tim)
	2014-04-01

	Code Index
	• line 0020: includes
	• line 0027: program memory declarations
	• line 1112: defines
	• line 1136: variable declarations
	• line 1246: setup()
	• line 1281: ISR(TIMER1_COMPA_vect)
	• line 1285: check_buttons()
	• line 1305: loop() [main program loop]
	• line 1571: delay_with_break(int ms)

*/

// include the library code:
#include <LiquidCrystal.h>
#include <MemoryFree.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>


// Mode 1: Kickstarter

// define the adjectives table in program memory
prog_char adj_00[] PROGMEM = "3D Printed";
prog_char adj_01[] PROGMEM = "American-Made";
prog_char adj_02[] PROGMEM = "Android-Powered";
prog_char adj_03[] PROGMEM = "Animatronic";
prog_char adj_04[] PROGMEM = "Arduino-Powered";
prog_char adj_05[] PROGMEM = "Artisan";
prog_char adj_06[] PROGMEM = "Atomic";
prog_char adj_07[] PROGMEM = "Augmented";
prog_char adj_08[] PROGMEM = "Authentic";
prog_char adj_09[] PROGMEM = "Bespoke";
prog_char adj_10[] PROGMEM = "Bluetooth";
prog_char adj_11[] PROGMEM = "Caffeine-Infused";
prog_char adj_12[] PROGMEM = "Desktop";
prog_char adj_13[] PROGMEM = "Electric";
prog_char adj_14[] PROGMEM = "Encrypted";
prog_char adj_15[] PROGMEM = "Etched";
prog_char adj_16[] PROGMEM = "Fully Automatic";
prog_char adj_17[] PROGMEM = "Fully Immersive";
prog_char adj_18[] PROGMEM = "Gigabit";
prog_char adj_19[] PROGMEM = "GPS-Enabled";
prog_char adj_20[] PROGMEM = "Hand-Carved";
prog_char adj_21[] PROGMEM = "Hand-Crafted";
prog_char adj_22[] PROGMEM = "Handheld";
prog_char adj_23[] PROGMEM = "Hands-Free";
prog_char adj_24[] PROGMEM = "HD";
prog_char adj_25[] PROGMEM = "Infrared";
prog_char adj_26[] PROGMEM = "Injection-Molded";
prog_char adj_27[] PROGMEM = "Laser-Cut";
prog_char adj_28[] PROGMEM = "Learning";
prog_char adj_29[] PROGMEM = "Light-Sensing";
prog_char adj_30[] PROGMEM = "Locally-Sourced";
prog_char adj_31[] PROGMEM = "Location-Aware";
prog_char adj_32[] PROGMEM = "Minimal";
prog_char adj_33[] PROGMEM = "Mobile-Friendly";
prog_char adj_34[] PROGMEM = "Motion-Sensing";
prog_char adj_35[] PROGMEM = "Nanotech";
prog_char adj_36[] PROGMEM = "Open Source";
prog_char adj_37[] PROGMEM = "Optical";
prog_char adj_38[] PROGMEM = "Organic";
prog_char adj_39[] PROGMEM = "Paleo";
prog_char adj_40[] PROGMEM = "Polychromatic";
prog_char adj_41[] PROGMEM = "Portable";
prog_char adj_42[] PROGMEM = "Powerful";
prog_char adj_43[] PROGMEM = "Machined";
prog_char adj_44[] PROGMEM = "Privacy-Enhanced";
prog_char adj_45[] PROGMEM = "Programmable";
prog_char adj_46[] PROGMEM = "Reclaimed";
prog_char adj_47[] PROGMEM = "Remote Control";
prog_char adj_48[] PROGMEM = "Retro";
prog_char adj_49[] PROGMEM = "RFID-Blocking";
prog_char adj_50[] PROGMEM = "Seamless";
prog_char adj_51[] PROGMEM = "Self-Balancing";
prog_char adj_52[] PROGMEM = "Slim";
prog_char adj_53[] PROGMEM = "Slow Motion";
prog_char adj_54[] PROGMEM = "Smart";
prog_char adj_55[] PROGMEM = "Solar-Powered";
prog_char adj_56[] PROGMEM = "Space-Age";
prog_char adj_57[] PROGMEM = "Steam-Powered";
prog_char adj_58[] PROGMEM = "Technicolor";
prog_char adj_59[] PROGMEM = "Temperature Sensing";
prog_char adj_60[] PROGMEM = "Ultra-Light";
prog_char adj_61[] PROGMEM = "Ultra-Private";
prog_char adj_62[] PROGMEM = "Ultra-Slim";
prog_char adj_63[] PROGMEM = "Ultra-Thin";
prog_char adj_64[] PROGMEM = "Ultraviolet";
prog_char adj_65[] PROGMEM = "Universal";
prog_char adj_66[] PROGMEM = "USB";
prog_char adj_67[] PROGMEM = "Vintage";
prog_char adj_68[] PROGMEM = "Virtual Reality";
prog_char adj_69[] PROGMEM = "Wearable";
prog_char adj_70[] PROGMEM = "Weathered";
prog_char adj_71[] PROGMEM = "Weight-Sensing";
prog_char adj_72[] PROGMEM = "Wi-Fi";
prog_char adj_73[] PROGMEM = "Wireless";
prog_char adj_74[] PROGMEM = "World's Fastest";
prog_char adj_75[] PROGMEM = "World's First";
prog_char adj_76[] PROGMEM = "World's Lightest";
prog_char adj_77[] PROGMEM = "World's Smartest";

PROGMEM const char *adj_table[] =
{
	adj_00,
	adj_01,
	adj_02,
	adj_03,
	adj_04,
	adj_05,
	adj_06,
	adj_07,
	adj_08,
	adj_09,
	adj_10,
	adj_11,
	adj_12,
	adj_13,
	adj_14,
	adj_15,
	adj_16,
	adj_17,
	adj_18,
	adj_19,
	adj_20,
	adj_21,
	adj_22,
	adj_23,
	adj_24,
	adj_25,
	adj_26,
	adj_27,
	adj_28,
	adj_29,
	adj_30,
	adj_31,
	adj_32,
	adj_33,
	adj_34,
	adj_35,
	adj_36,
	adj_37,
	adj_38,
	adj_39,
	adj_40,
	adj_41,
	adj_42,
	adj_43,
	adj_44,
	adj_45,
	adj_46,
	adj_47,
	adj_48,
	adj_49,
	adj_50,
	adj_51,
	adj_52,
	adj_53,
	adj_54,
	adj_55,
	adj_56,
	adj_57,
	adj_58,
	adj_59,
	adj_60,
	adj_61,
	adj_62,
	adj_63,
	adj_64,
	adj_65,
	adj_66,
	adj_67,
	adj_68,
	adj_69,
	adj_70,
	adj_71,
	adj_72,
	adj_73,
	adj_74,
	adj_75,
	adj_76,
	adj_77};

//define the materials table in program memory
prog_char mat_00[] PROGMEM = "Acrylic";
prog_char mat_01[] PROGMEM = "Alpaca Wool";
prog_char mat_02[] PROGMEM = "Aluminum";
prog_char mat_03[] PROGMEM = "Bamboo";
prog_char mat_04[] PROGMEM = "Bitcoin";
prog_char mat_05[] PROGMEM = "BPA-Free";
prog_char mat_06[] PROGMEM = "Brass";
prog_char mat_07[] PROGMEM = "Canvas";
prog_char mat_08[] PROGMEM = "Carbon Fibre";
prog_char mat_09[] PROGMEM = "Cardboard";
prog_char mat_10[] PROGMEM = "Cast Iron";
prog_char mat_11[] PROGMEM = "Ceramic";
prog_char mat_12[] PROGMEM = "Cherry";
prog_char mat_13[] PROGMEM = "Composite";
prog_char mat_14[] PROGMEM = "Copper";
prog_char mat_15[] PROGMEM = "Cork";
prog_char mat_16[] PROGMEM = "Cotton";
prog_char mat_17[] PROGMEM = "Denim";
prog_char mat_18[] PROGMEM = "Digital";
prog_char mat_19[] PROGMEM = "Elastic";
prog_char mat_20[] PROGMEM = "Gabon Ebony";
prog_char mat_21[] PROGMEM = "Glass";
prog_char mat_22[] PROGMEM = "Gypsum";
prog_char mat_23[] PROGMEM = "Hardwood";
prog_char mat_24[] PROGMEM = "Hickory";
prog_char mat_25[] PROGMEM = "Leather";
prog_char mat_26[] PROGMEM = "LED";
prog_char mat_27[] PROGMEM = "Magnetic";
prog_char mat_28[] PROGMEM = "Mahogany";
prog_char mat_29[] PROGMEM = "Marblewood";
prog_char mat_30[] PROGMEM = "Mechanical";
prog_char mat_31[] PROGMEM = "Memory Foam";
prog_char mat_32[] PROGMEM = "Microfiber";
prog_char mat_33[] PROGMEM = "Obsidian";
prog_char mat_34[] PROGMEM = "OLED";
prog_char mat_35[] PROGMEM = "Online";
prog_char mat_36[] PROGMEM = "Organic";
prog_char mat_37[] PROGMEM = "Paper";
prog_char mat_38[] PROGMEM = "Papier-Mache";
prog_char mat_39[] PROGMEM = "Peruvian Walnut";
prog_char mat_40[] PROGMEM = "Pewter";
prog_char mat_41[] PROGMEM = "Plaster";
prog_char mat_42[] PROGMEM = "Polyester";
prog_char mat_43[] PROGMEM = "Polymer";
prog_char mat_44[] PROGMEM = "Programming";
prog_char mat_45[] PROGMEM = "Pumice";
prog_char mat_46[] PROGMEM = "Pyrite";
prog_char mat_47[] PROGMEM = "Quartz";
prog_char mat_48[] PROGMEM = "Resin";
prog_char mat_49[] PROGMEM = "Silicone";
prog_char mat_50[] PROGMEM = "Spandex";
prog_char mat_51[] PROGMEM = "Stainless Steel";
prog_char mat_52[] PROGMEM = "Stone";
prog_char mat_53[] PROGMEM = "Styrofoam";
prog_char mat_54[] PROGMEM = "Teak";
prog_char mat_55[] PROGMEM = "Teflon";
prog_char mat_56[] PROGMEM = "Titanium";
prog_char mat_57[] PROGMEM = "Vinyl";
prog_char mat_58[] PROGMEM = "Wax";
prog_char mat_59[] PROGMEM = "Wicker";

PROGMEM const char *mat_table[] =
{
	mat_00,
	mat_01,
	mat_02,
	mat_03,
	mat_04,
	mat_05,
	mat_06,
	mat_07,
	mat_08,
	mat_09,
	mat_10,
	mat_11,
	mat_12,
	mat_13,
	mat_14,
	mat_15,
	mat_16,
	mat_17,
	mat_18,
	mat_19,
	mat_20,
	mat_21,
	mat_22,
	mat_23,
	mat_24,
	mat_25,
	mat_26,
	mat_27,
	mat_28,
	mat_29,
	mat_30,
	mat_31,
	mat_32,
	mat_33,
	mat_34,
	mat_35,
	mat_36,
	mat_37,
	mat_38,
	mat_39,
	mat_40,
	mat_41,
	mat_42,
	mat_43,
	mat_44,
	mat_45,
	mat_46,
	mat_47,
	mat_48,
	mat_49,
	mat_50,
	mat_51,
	mat_52,
	mat_53,
	mat_54,
	mat_55,
	mat_56,
	mat_57,
	mat_58,
	mat_59};

//define the noun table in program memory
prog_char noun_00[] PROGMEM = "3D Printer";
prog_char noun_01[] PROGMEM = "Activity Tracker";
prog_char noun_02[] PROGMEM = "Adapter";
prog_char noun_03[] PROGMEM = "Amplifier";
prog_char noun_04[] PROGMEM = "Backpack";
prog_char noun_05[] PROGMEM = "Beard Trimmer";
prog_char noun_06[] PROGMEM = "Belt";
prog_char noun_07[] PROGMEM = "Bike Headlight";
prog_char noun_08[] PROGMEM = "Bicycle Seat";
prog_char noun_09[] PROGMEM = "Blender";
prog_char noun_10[] PROGMEM = "Book";
prog_char noun_11[] PROGMEM = "Button";
prog_char noun_12[] PROGMEM = "Calculator";
prog_char noun_13[] PROGMEM = "Camera";
prog_char noun_14[] PROGMEM = "Chair";
prog_char noun_15[] PROGMEM = "Clock";
prog_char noun_16[] PROGMEM = "Coffee Mug";
prog_char noun_17[] PROGMEM = "Compost Bin";
prog_char noun_18[] PROGMEM = "Credit Card";
prog_char noun_19[] PROGMEM = "Cutting Board";
prog_char noun_20[] PROGMEM = "Desk";
prog_char noun_21[] PROGMEM = "Dice";
prog_char noun_22[] PROGMEM = "Doorbell";
prog_char noun_23[] PROGMEM = "Doorknob";
prog_char noun_24[] PROGMEM = "Earmuffs";
prog_char noun_25[] PROGMEM = "Espresso Machine";
prog_char noun_26[] PROGMEM = "Exercise Monitor";
prog_char noun_27[] PROGMEM = "Fish Tank";
prog_char noun_28[] PROGMEM = "Flashlight";
prog_char noun_29[] PROGMEM = "Fruit Peeler";
prog_char noun_30[] PROGMEM = "Game Console";
prog_char noun_31[] PROGMEM = "Gloves";
prog_char noun_32[] PROGMEM = "Gramophone";
prog_char noun_33[] PROGMEM = "Gyroscope";
prog_char noun_34[] PROGMEM = "Hat";
prog_char noun_35[] PROGMEM = "Headphones";
prog_char noun_36[] PROGMEM = "iPhone Case";
prog_char noun_37[] PROGMEM = "iPhone Dock";
prog_char noun_38[] PROGMEM = "Kayak";
prog_char noun_39[] PROGMEM = "Key Case";
prog_char noun_40[] PROGMEM = "Thermometer";
prog_char noun_41[] PROGMEM = "Lamp";
prog_char noun_42[] PROGMEM = "Leash";
prog_char noun_43[] PROGMEM = "Leggings";
prog_char noun_44[] PROGMEM = "Lens";
prog_char noun_45[] PROGMEM = "Light Bulb";
prog_char noun_46[] PROGMEM = "Light Switch";
prog_char noun_47[] PROGMEM = "Lucid Dream Mask";
prog_char noun_48[] PROGMEM = "Lunchbox";
prog_char noun_49[] PROGMEM = "Microcopter";
prog_char noun_50[] PROGMEM = "Microcomputer";
prog_char noun_51[] PROGMEM = "Mittens";
prog_char noun_52[] PROGMEM = "Mixing Board";
prog_char noun_53[] PROGMEM = "Mug Warmer";
prog_char noun_54[] PROGMEM = "Night Light";
prog_char noun_55[] PROGMEM = "Notepad";
prog_char noun_56[] PROGMEM = "Oven Mitt";
prog_char noun_57[] PROGMEM = "Pen";
prog_char noun_58[] PROGMEM = "Pencil";
prog_char noun_59[] PROGMEM = "Pencil Sharpener";
prog_char noun_60[] PROGMEM = "Ping Pong Paddle";
prog_char noun_61[] PROGMEM = "Plant Monitor";
prog_char noun_62[] PROGMEM = "Quadcopter";
prog_char noun_63[] PROGMEM = "Robot";
prog_char noun_64[] PROGMEM = "Scanner";
prog_char noun_65[] PROGMEM = "Scarf";
prog_char noun_66[] PROGMEM = "Scooter";
prog_char noun_67[] PROGMEM = "Screwdriver";
prog_char noun_68[] PROGMEM = "Skateboard";
prog_char noun_69[] PROGMEM = "Sleeping Mask";
prog_char noun_70[] PROGMEM = "Smartwatch";
prog_char noun_71[] PROGMEM = "Smoke Detector";
prog_char noun_72[] PROGMEM = "Sous Vide Circulator";
prog_char noun_73[] PROGMEM = "Speaker";
prog_char noun_74[] PROGMEM = "Spinning Top";
prog_char noun_75[] PROGMEM = "Stylus";
prog_char noun_76[] PROGMEM = "Sunglasses";
prog_char noun_77[] PROGMEM = "Sweater";
prog_char noun_78[] PROGMEM = "Tea Infuser";
prog_char noun_79[] PROGMEM = "Thermostat";
prog_char noun_80[] PROGMEM = "Toothbrush";
prog_char noun_81[] PROGMEM = "Treadmill";
prog_char noun_82[] PROGMEM = "Tripod";
prog_char noun_83[] PROGMEM = "Ukulele";
prog_char noun_84[] PROGMEM = "Unicycle";
prog_char noun_85[] PROGMEM = "Utility Knife";
prog_char noun_86[] PROGMEM = "Wallet";
prog_char noun_87[] PROGMEM = "Water Bottle";
prog_char noun_88[] PROGMEM = "Whiskey Rocks";
prog_char noun_89[] PROGMEM = "Wristwatch";

PROGMEM const char *noun_table[] =
{
	noun_00,
	noun_01,
	noun_02,
	noun_03,
	noun_04,
	noun_05,
	noun_06,
	noun_07,
	noun_08,
	noun_09,
	noun_10,
	noun_11,
	noun_12,
	noun_13,
	noun_14,
	noun_15,
	noun_16,
	noun_17,
	noun_18,
	noun_19,
	noun_20,
	noun_21,
	noun_22,
	noun_23,
	noun_24,
	noun_25,
	noun_26,
	noun_27,
	noun_28,
	noun_29,
	noun_30,
	noun_31,
	noun_32,
	noun_33,
	noun_34,
	noun_35,
	noun_36,
	noun_37,
	noun_38,
	noun_39,
	noun_40,
	noun_41,
	noun_42,
	noun_43,
	noun_44,
	noun_45,
	noun_46,
	noun_47,
	noun_48,
	noun_49,
	noun_50,
	noun_51,
	noun_52,
	noun_53,
	noun_54,
	noun_55,
	noun_56,
	noun_57,
	noun_58,
	noun_59,
	noun_60,
	noun_61,
	noun_62,
	noun_63,
	noun_64,
	noun_65,
	noun_66,
	noun_67,
	noun_68,
	noun_69,
	noun_70,
	noun_71,
	noun_72,
	noun_73,
	noun_74,
	noun_75,
	noun_76,
	noun_77,
	noun_78,
	noun_79,
	noun_80,
	noun_81,
	noun_82,
	noun_83,
	noun_84,
	noun_85,
	noun_86,
	noun_87,
	noun_88,
	noun_89};

//define the "for X" array in program memory
prog_char for_00[] PROGMEM = "for Babies";
prog_char for_01[] PROGMEM = "for Boys";
prog_char for_02[] PROGMEM = "for Cats";
prog_char for_03[] PROGMEM = "for Dads";
prog_char for_04[] PROGMEM = "for Dogs";
prog_char for_05[] PROGMEM = "for Girls";
prog_char for_06[] PROGMEM = "for Hamsters";
prog_char for_07[] PROGMEM = "for Kids";
prog_char for_08[] PROGMEM = "for Llamas";
prog_char for_09[] PROGMEM = "for Moms";

PROGMEM const char *for_table[] =
{
	for_00,
	for_01,
	for_02,
	for_03,
	for_04,
	for_05,
	for_06,
	for_07,
	for_08,
	for_09};


// Mode 2: Board Game

// define the board game adjectives table in program memory
prog_char M2_adj_00[] PROGMEM = "Abstract";
prog_char M2_adj_01[] PROGMEM = "Educational";
prog_char M2_adj_02[] PROGMEM = "Fun";
prog_char M2_adj_03[] PROGMEM = "Historically Accurate";
prog_char M2_adj_04[] PROGMEM = "Minimalist";
prog_char M2_adj_05[] PROGMEM = "Print & Play";
prog_char M2_adj_06[] PROGMEM = "Real-Time";
prog_char M2_adj_07[] PROGMEM = "Retro";
prog_char M2_adj_08[] PROGMEM = "Serious";
prog_char M2_adj_09[] PROGMEM = "Silly";
prog_char M2_adj_10[] PROGMEM = "Unique";


PROGMEM const char *M2_adj_table[] =
{
	M2_adj_00,
	M2_adj_01,
	M2_adj_02,
	M2_adj_03,
	M2_adj_04,
	M2_adj_05,
	M2_adj_06,
	M2_adj_07,
	M2_adj_08,
	M2_adj_09,
	M2_adj_10};


// define the board game themes table in program memory
prog_char M2_thm_00[] PROGMEM = "Ancient Greece";
prog_char M2_thm_01[] PROGMEM = "Animal Husbandry";
prog_char M2_thm_02[] PROGMEM = "Animal Migration";
prog_char M2_thm_03[] PROGMEM = "Army Building";
prog_char M2_thm_04[] PROGMEM = "Assassination";
prog_char M2_thm_05[] PROGMEM = "Bible";
prog_char M2_thm_06[] PROGMEM = "Building";
prog_char M2_thm_07[] PROGMEM = "Business";
prog_char M2_thm_08[] PROGMEM = "City Building";
prog_char M2_thm_09[] PROGMEM = "Civil War";
prog_char M2_thm_10[] PROGMEM = "Coffee Brewing";
prog_char M2_thm_11[] PROGMEM = "Construction";
prog_char M2_thm_12[] PROGMEM = "Cooking";
prog_char M2_thm_13[] PROGMEM = "Corporate Espionage";
prog_char M2_thm_14[] PROGMEM = "Death Prediction";
prog_char M2_thm_15[] PROGMEM = "Desert";
prog_char M2_thm_16[] PROGMEM = "Dinosaur";
prog_char M2_thm_17[] PROGMEM = "Disaster";
prog_char M2_thm_18[] PROGMEM = "Dystopian";
prog_char M2_thm_19[] PROGMEM = "Employment";
prog_char M2_thm_20[] PROGMEM = "Engineering";
prog_char M2_thm_21[] PROGMEM = "Fantasy";
prog_char M2_thm_22[] PROGMEM = "Farming";
prog_char M2_thm_23[] PROGMEM = "Fishing";
prog_char M2_thm_24[] PROGMEM = "Gardening";
prog_char M2_thm_25[] PROGMEM = "Goat Herding";
prog_char M2_thm_26[] PROGMEM = "Graphic Design";
prog_char M2_thm_27[] PROGMEM = "Grocery Shopping";
prog_char M2_thm_28[] PROGMEM = "Herding";
prog_char M2_thm_29[] PROGMEM = "Horror";
prog_char M2_thm_30[] PROGMEM = "Hot Dog";
prog_char M2_thm_31[] PROGMEM = "Interior Design";
prog_char M2_thm_32[] PROGMEM = "Internet Startup";
prog_char M2_thm_33[] PROGMEM = "Island";
prog_char M2_thm_34[] PROGMEM = "Jane Austen";
prog_char M2_thm_35[] PROGMEM = "Jungle";
prog_char M2_thm_36[] PROGMEM = "Logging";
prog_char M2_thm_37[] PROGMEM = "Medieval";
prog_char M2_thm_38[] PROGMEM = "Mining";
prog_char M2_thm_39[] PROGMEM = "Mystery";
prog_char M2_thm_40[] PROGMEM = "Ninja";
prog_char M2_thm_41[] PROGMEM = "Painting";
prog_char M2_thm_42[] PROGMEM = "Pillow Fight";
prog_char M2_thm_43[] PROGMEM = "Pirate";
prog_char M2_thm_44[] PROGMEM = "Power Plant";
prog_char M2_thm_45[] PROGMEM = "Programming";
prog_char M2_thm_46[] PROGMEM = "Restaurant";
prog_char M2_thm_47[] PROGMEM = "Space";
prog_char M2_thm_48[] PROGMEM = "Spy";
prog_char M2_thm_49[] PROGMEM = "Steampunk";
prog_char M2_thm_50[] PROGMEM = "Super Hero";
prog_char M2_thm_51[] PROGMEM = "Super Villain";
prog_char M2_thm_52[] PROGMEM = "Surveillance";
prog_char M2_thm_53[] PROGMEM = "Time Travel";
prog_char M2_thm_54[] PROGMEM = "Train";
prog_char M2_thm_55[] PROGMEM = "Transportation";
prog_char M2_thm_56[] PROGMEM = "Trucking";
prog_char M2_thm_57[] PROGMEM = "Underwater";
prog_char M2_thm_58[] PROGMEM = "Vikings";
prog_char M2_thm_59[] PROGMEM = "Western";
prog_char M2_thm_60[] PROGMEM = "Wizard";
prog_char M2_thm_61[] PROGMEM = "WW2";
prog_char M2_thm_62[] PROGMEM = "Zombie";


PROGMEM const char *M2_thm_table[] =
{
	M2_thm_00,
	M2_thm_01,
	M2_thm_02,
	M2_thm_03,
	M2_thm_04,
	M2_thm_05,
	M2_thm_06,
	M2_thm_07,
	M2_thm_08,
	M2_thm_09,
	M2_thm_10,
	M2_thm_11,
	M2_thm_12,
	M2_thm_13,
	M2_thm_14,
	M2_thm_15,
	M2_thm_16,
	M2_thm_17,
	M2_thm_18,
	M2_thm_19,
	M2_thm_20,
	M2_thm_21,
	M2_thm_22,
	M2_thm_23,
	M2_thm_24,
	M2_thm_25,
	M2_thm_26,
	M2_thm_27,
	M2_thm_28,
	M2_thm_29,
	M2_thm_30,
	M2_thm_31,
	M2_thm_32,
	M2_thm_33,
	M2_thm_34,
	M2_thm_35,
	M2_thm_36,
	M2_thm_37,
	M2_thm_38,
	M2_thm_39,
	M2_thm_40,
	M2_thm_41,
	M2_thm_42,
	M2_thm_43,
	M2_thm_44,
	M2_thm_45,
	M2_thm_46,
	M2_thm_47,
	M2_thm_48,
	M2_thm_49,
	M2_thm_50,
	M2_thm_51,
	M2_thm_52,
	M2_thm_53,
	M2_thm_54,
	M2_thm_55,
	M2_thm_56,
	M2_thm_57,
	M2_thm_58,
	M2_thm_59,
	M2_thm_60,
	M2_thm_61,
	M2_thm_62};


// define the board game types table in program memory
prog_char M2_typ_00[] PROGMEM = "Adventure";
prog_char M2_typ_01[] PROGMEM = "Baseball";
prog_char M2_typ_02[] PROGMEM = "Betting";
prog_char M2_typ_03[] PROGMEM = "Bidding";
prog_char M2_typ_04[] PROGMEM = "Bluffing";
prog_char M2_typ_05[] PROGMEM = "Card";
prog_char M2_typ_06[] PROGMEM = "Card Battle";
prog_char M2_typ_07[] PROGMEM = "Collectible Card";
prog_char M2_typ_08[] PROGMEM = "Cooperative";
prog_char M2_typ_09[] PROGMEM = "Deck Building";
prog_char M2_typ_10[] PROGMEM = "Dexterity";
prog_char M2_typ_11[] PROGMEM = "Dice";
prog_char M2_typ_12[] PROGMEM = "Dodgeball";
prog_char M2_typ_13[] PROGMEM = "Drinking";
prog_char M2_typ_14[] PROGMEM = "Euro";
prog_char M2_typ_15[] PROGMEM = "Exploration";
prog_char M2_typ_16[] PROGMEM = "Football";
prog_char M2_typ_17[] PROGMEM = "Hidden Movement";
prog_char M2_typ_18[] PROGMEM = "Historical";
prog_char M2_typ_19[] PROGMEM = "Miniatures";
prog_char M2_typ_20[] PROGMEM = "Party";
prog_char M2_typ_21[] PROGMEM = "Party";
prog_char M2_typ_22[] PROGMEM = "Pickup & Deliver";
prog_char M2_typ_23[] PROGMEM = "Press Your Luck";
prog_char M2_typ_24[] PROGMEM = "Puzzle";
prog_char M2_typ_25[] PROGMEM = "Resource Management";
prog_char M2_typ_26[] PROGMEM = "Roll and Move";
prog_char M2_typ_27[] PROGMEM = "RPG";
prog_char M2_typ_28[] PROGMEM = "Sport";
prog_char M2_typ_29[] PROGMEM = "Storytelling";
prog_char M2_typ_30[] PROGMEM = "Strategy";
prog_char M2_typ_31[] PROGMEM = "Tactical Card";
prog_char M2_typ_32[] PROGMEM = "Territory Control";
prog_char M2_typ_33[] PROGMEM = "Tile-Laying";
prog_char M2_typ_34[] PROGMEM = "Trading";
prog_char M2_typ_35[] PROGMEM = "War";
prog_char M2_typ_36[] PROGMEM = "Worker Placement";


PROGMEM const char *M2_typ_table[] =
{
	M2_typ_00,
	M2_typ_01,
	M2_typ_02,
	M2_typ_03,
	M2_typ_04,
	M2_typ_05,
	M2_typ_06,
	M2_typ_07,
	M2_typ_08,
	M2_typ_09,
	M2_typ_10,
	M2_typ_11,
	M2_typ_12,
	M2_typ_13,
	M2_typ_14,
	M2_typ_15,
	M2_typ_16,
	M2_typ_17,
	M2_typ_18,
	M2_typ_19,
	M2_typ_20,
	M2_typ_21,
	M2_typ_22,
	M2_typ_23,
	M2_typ_24,
	M2_typ_25,
	M2_typ_26,
	M2_typ_27,
	M2_typ_28,
	M2_typ_29,
	M2_typ_30,
	M2_typ_31,
	M2_typ_32,
	M2_typ_33,
	M2_typ_34,
	M2_typ_35,
	M2_typ_36};


// define the board game "withs" table in program memory
prog_char M2_wth_00[] PROGMEM = "a CD Soundtrack";
prog_char M2_wth_01[] PROGMEM = "a Hardwood Board";
prog_char M2_wth_02[] PROGMEM = "a Hardwood Case";
prog_char M2_wth_03[] PROGMEM = "a Hex Map";
prog_char M2_wth_04[] PROGMEM = "a Random Board";
prog_char M2_wth_05[] PROGMEM = "a Tin Box";
prog_char M2_wth_06[] PROGMEM = "Asymmetry";
prog_char M2_wth_07[] PROGMEM = "Brass Pieces";
prog_char M2_wth_08[] PROGMEM = "Cardboard Standees";
prog_char M2_wth_09[] PROGMEM = "Clay Poker Chips";
prog_char M2_wth_10[] PROGMEM = "Custom Dice";
prog_char M2_wth_11[] PROGMEM = "Custom Meeples";
prog_char M2_wth_12[] PROGMEM = "Electronic Timer";
prog_char M2_wth_13[] PROGMEM = "Metal Coins";
prog_char M2_wth_14[] PROGMEM = "Online Elements";
prog_char M2_wth_15[] PROGMEM = "Pewter Figurines";
prog_char M2_wth_16[] PROGMEM = "Real Lasers";
prog_char M2_wth_17[] PROGMEM = "Sand Timers";
prog_char M2_wth_18[] PROGMEM = "Wood Tokens";


PROGMEM const char *M2_wth_table[] =
{
	M2_wth_00,
	M2_wth_01,
	M2_wth_02,
	M2_wth_03,
	M2_wth_04,
	M2_wth_05,
	M2_wth_06,
	M2_wth_07,
	M2_wth_08,
	M2_wth_09,
	M2_wth_10,
	M2_wth_11,
	M2_wth_12,
	M2_wth_13,
	M2_wth_14,
	M2_wth_15,
	M2_wth_16,
	M2_wth_17,
	M2_wth_18};


// Mode 3: Indie Video Game

// define the Video Game adjectives table in program memory
prog_char M3_adj_00[] PROGMEM = "16-bit";
prog_char M3_adj_01[] PROGMEM = "8-bit";
prog_char M3_adj_02[] PROGMEM = "Asymmetrical";
prog_char M3_adj_03[] PROGMEM = "Colorful";
prog_char M3_adj_04[] PROGMEM = "Educational";
prog_char M3_adj_05[] PROGMEM = "Fast-Paced";
prog_char M3_adj_06[] PROGMEM = "Mature";
prog_char M3_adj_07[] PROGMEM = "Mind-Bending";
prog_char M3_adj_08[] PROGMEM = "One-Button";
prog_char M3_adj_09[] PROGMEM = "Open World";
prog_char M3_adj_10[] PROGMEM = "Original";
prog_char M3_adj_11[] PROGMEM = "Painterly";
prog_char M3_adj_12[] PROGMEM = "Pixel Art";
prog_char M3_adj_13[] PROGMEM = "Point & Click";
prog_char M3_adj_14[] PROGMEM = "Retro";
prog_char M3_adj_15[] PROGMEM = "Ridiculous";
prog_char M3_adj_16[] PROGMEM = "Team-Based";
prog_char M3_adj_17[] PROGMEM = "Text-Based";
prog_char M3_adj_18[] PROGMEM = "Voxel-Based";


PROGMEM const char *M3_adj_table[] =
{
	M3_adj_00,
	M3_adj_01,
	M3_adj_02,
	M3_adj_03,
	M3_adj_04,
	M3_adj_05,
	M3_adj_06,
	M3_adj_07,
	M3_adj_08,
	M3_adj_09,
	M3_adj_10,
	M3_adj_11,
	M3_adj_12,
	M3_adj_13,
	M3_adj_14,
	M3_adj_15,
	M3_adj_16,
	M3_adj_17,
	M3_adj_18};

// define the video game themes table in program memory
prog_char M3_thm_00[] PROGMEM = "Alien";
prog_char M3_thm_01[] PROGMEM = "Ancient Greece";
prog_char M3_thm_02[] PROGMEM = "Animal Husbandry";
prog_char M3_thm_03[] PROGMEM = "Animal Migration";
prog_char M3_thm_04[] PROGMEM = "Aquarium";
prog_char M3_thm_05[] PROGMEM = "Army Building";
prog_char M3_thm_06[] PROGMEM = "Assassination";
prog_char M3_thm_07[] PROGMEM = "Bible";
prog_char M3_thm_08[] PROGMEM = "Business";
prog_char M3_thm_09[] PROGMEM = "City Building";
prog_char M3_thm_10[] PROGMEM = "Civil War";
prog_char M3_thm_11[] PROGMEM = "Construction";
prog_char M3_thm_12[] PROGMEM = "Cooking";
prog_char M3_thm_13[] PROGMEM = "Corporate Espionage";
prog_char M3_thm_14[] PROGMEM = "Dance";
prog_char M3_thm_15[] PROGMEM = "Dating";
prog_char M3_thm_16[] PROGMEM = "Death";
prog_char M3_thm_17[] PROGMEM = "Desert";
prog_char M3_thm_18[] PROGMEM = "Dinosaur";
prog_char M3_thm_19[] PROGMEM = "Disaster";
prog_char M3_thm_20[] PROGMEM = "Dystopian";
prog_char M3_thm_21[] PROGMEM = "Employment";
prog_char M3_thm_22[] PROGMEM = "Engineering";
prog_char M3_thm_23[] PROGMEM = "Exercise";
prog_char M3_thm_24[] PROGMEM = "Fantasy";
prog_char M3_thm_25[] PROGMEM = "Farming";
prog_char M3_thm_26[] PROGMEM = "Fishing";
prog_char M3_thm_27[] PROGMEM = "Gardening";
prog_char M3_thm_28[] PROGMEM = "Goat";
prog_char M3_thm_29[] PROGMEM = "Graphic Design";
prog_char M3_thm_30[] PROGMEM = "Grocery Shopping";
prog_char M3_thm_31[] PROGMEM = "Herding";
prog_char M3_thm_32[] PROGMEM = "Horror";
prog_char M3_thm_33[] PROGMEM = "Hot Dog";
prog_char M3_thm_34[] PROGMEM = "Interior Design";
prog_char M3_thm_35[] PROGMEM = "Island";
prog_char M3_thm_36[] PROGMEM = "Jane Austen";
prog_char M3_thm_37[] PROGMEM = "Jungle";
prog_char M3_thm_38[] PROGMEM = "LEGO-like";
prog_char M3_thm_39[] PROGMEM = "Medieval";
prog_char M3_thm_40[] PROGMEM = "Mining";
prog_char M3_thm_41[] PROGMEM = "Music";
prog_char M3_thm_42[] PROGMEM = "Mystery";
prog_char M3_thm_43[] PROGMEM = "Nazi";
prog_char M3_thm_44[] PROGMEM = "Ninja";
prog_char M3_thm_45[] PROGMEM = "Noire";
prog_char M3_thm_46[] PROGMEM = "Painting";
prog_char M3_thm_47[] PROGMEM = "Pillow Fight";
prog_char M3_thm_48[] PROGMEM = "Pirate";
prog_char M3_thm_49[] PROGMEM = "Power Plant";
prog_char M3_thm_50[] PROGMEM = "Programming";
prog_char M3_thm_51[] PROGMEM = "Restaurant";
prog_char M3_thm_52[] PROGMEM = "Rythm";
prog_char M3_thm_53[] PROGMEM = "Space";
prog_char M3_thm_54[] PROGMEM = "Space Marine";
prog_char M3_thm_55[] PROGMEM = "Spy";
prog_char M3_thm_56[] PROGMEM = "Steampunk";
prog_char M3_thm_57[] PROGMEM = "Super Hero";
prog_char M3_thm_58[] PROGMEM = "Super Villian";
prog_char M3_thm_59[] PROGMEM = "Surveillance";
prog_char M3_thm_60[] PROGMEM = "Time Travel";
prog_char M3_thm_61[] PROGMEM = "Time-Shifting";
prog_char M3_thm_62[] PROGMEM = "Train";
prog_char M3_thm_63[] PROGMEM = "Transportation";
prog_char M3_thm_64[] PROGMEM = "Trucking";
prog_char M3_thm_65[] PROGMEM = "Underwater";
prog_char M3_thm_66[] PROGMEM = "Vikings";
prog_char M3_thm_67[] PROGMEM = "Western";
prog_char M3_thm_68[] PROGMEM = "Wizard";
prog_char M3_thm_69[] PROGMEM = "WW2";
prog_char M3_thm_70[] PROGMEM = "Zombie";

PROGMEM const char *M3_thm_table[] =
{
	M3_thm_00,
	M3_thm_01,
	M3_thm_02,
	M3_thm_03,
	M3_thm_04,
	M3_thm_05,
	M3_thm_06,
	M3_thm_07,
	M3_thm_08,
	M3_thm_09,
	M3_thm_10,
	M3_thm_11,
	M3_thm_12,
	M3_thm_13,
	M3_thm_14,
	M3_thm_15,
	M3_thm_16,
	M3_thm_17,
	M3_thm_18,
	M3_thm_19,
	M3_thm_20,
	M3_thm_21,
	M3_thm_22,
	M3_thm_23,
	M3_thm_24,
	M3_thm_25,
	M3_thm_26,
	M3_thm_27,
	M3_thm_28,
	M3_thm_29,
	M3_thm_30,
	M3_thm_31,
	M3_thm_32,
	M3_thm_33,
	M3_thm_34,
	M3_thm_35,
	M3_thm_36,
	M3_thm_37,
	M3_thm_38,
	M3_thm_39,
	M3_thm_40,
	M3_thm_41,
	M3_thm_42,
	M3_thm_43,
	M3_thm_44,
	M3_thm_45,
	M3_thm_46,
	M3_thm_47,
	M3_thm_48,
	M3_thm_49,
	M3_thm_50,
	M3_thm_51,
	M3_thm_52,
	M3_thm_53,
	M3_thm_54,
	M3_thm_55,
	M3_thm_56,
	M3_thm_57,
	M3_thm_58,
	M3_thm_59,
	M3_thm_60,
	M3_thm_61,
	M3_thm_62,
	M3_thm_63,
	M3_thm_64,
	M3_thm_65,
	M3_thm_66,
	M3_thm_67,
	M3_thm_68,
	M3_thm_69,
	M3_thm_70};

// define the video game types table in program memory
prog_char M3_typ_00[] PROGMEM = "Action";
prog_char M3_typ_01[] PROGMEM = "Adventure";
prog_char M3_typ_02[] PROGMEM = "Beat 'em Up";
prog_char M3_typ_03[] PROGMEM = "Brawler";
prog_char M3_typ_04[] PROGMEM = "City Simulator";
prog_char M3_typ_05[] PROGMEM = "Fighting";
prog_char M3_typ_06[] PROGMEM = "FPS";
prog_char M3_typ_07[] PROGMEM = "God";
prog_char M3_typ_08[] PROGMEM = "Horror";
prog_char M3_typ_09[] PROGMEM = "Matching";
prog_char M3_typ_10[] PROGMEM = "Maze";
prog_char M3_typ_11[] PROGMEM = "Metroidvania";
prog_char M3_typ_12[] PROGMEM = "MMO";
prog_char M3_typ_13[] PROGMEM = "MMORPG";
prog_char M3_typ_14[] PROGMEM = "MMORTS";
prog_char M3_typ_15[] PROGMEM = "MOBA";
prog_char M3_typ_16[] PROGMEM = "Party";
prog_char M3_typ_17[] PROGMEM = "Pinball";
prog_char M3_typ_18[] PROGMEM = "Platformer";
prog_char M3_typ_19[] PROGMEM = "Puzzle";
prog_char M3_typ_20[] PROGMEM = "Racing";
prog_char M3_typ_21[] PROGMEM = "Rail Shooter";
prog_char M3_typ_22[] PROGMEM = "Real-Time Strategy";
prog_char M3_typ_23[] PROGMEM = "Roguelike";
prog_char M3_typ_24[] PROGMEM = "RPG";
prog_char M3_typ_25[] PROGMEM = "Sandbox";
prog_char M3_typ_26[] PROGMEM = "Simulator";
prog_char M3_typ_27[] PROGMEM = "Stealth";
prog_char M3_typ_28[] PROGMEM = "Survival";
prog_char M3_typ_29[] PROGMEM = "Tactics";
prog_char M3_typ_30[] PROGMEM = "Tower Defense";
prog_char M3_typ_31[] PROGMEM = "Turn-Based Strategy";


PROGMEM const char *M3_typ_table[] =
{
	M3_typ_00,
	M3_typ_01,
	M3_typ_02,
	M3_typ_03,
	M3_typ_04,
	M3_typ_05,
	M3_typ_06,
	M3_typ_07,
	M3_typ_08,
	M3_typ_09,
	M3_typ_10,
	M3_typ_11,
	M3_typ_12,
	M3_typ_13,
	M3_typ_14,
	M3_typ_15,
	M3_typ_16,
	M3_typ_17,
	M3_typ_18,
	M3_typ_19,
	M3_typ_20,
	M3_typ_21,
	M3_typ_22,
	M3_typ_23,
	M3_typ_24,
	M3_typ_25,
	M3_typ_26,
	M3_typ_27,
	M3_typ_28,
	M3_typ_29,
	M3_typ_30,
	M3_typ_31};

// define the video game "for X" table in program memory
prog_char M3_for_00[] PROGMEM = "Android";
prog_char M3_for_01[] PROGMEM = "Atari 2600";
prog_char M3_for_02[] PROGMEM = "Dreamcast";
prog_char M3_for_03[] PROGMEM = "Gamecube";
prog_char M3_for_04[] PROGMEM = "GCW Zero";
prog_char M3_for_05[] PROGMEM = "Goats";
prog_char M3_for_06[] PROGMEM = "Kids";
prog_char M3_for_07[] PROGMEM = "Linux";
prog_char M3_for_08[] PROGMEM = "Raspberry Pi";
prog_char M3_for_09[] PROGMEM = "Steam";
prog_char M3_for_10[] PROGMEM = "Tablets";
prog_char M3_for_11[] PROGMEM = "WiiU";

PROGMEM const char *M3_for_table[] =
{
	M3_for_00,
	M3_for_01,
	M3_for_02,
	M3_for_03,
	M3_for_04,
	M3_for_05,
	M3_for_06,
	M3_for_07,
	M3_for_08,
	M3_for_09,
	M3_for_10,
	M3_for_11};



char buffer[24];    // make sure this is large enough for the largest string it must hold

// Mode 1: Kickstarter - array sizes
#define numAdj1 78
#define numAdj2 74
#define numMat 60
#define numNouns 90
#define numFors 10

// Mode 2: Board Game - array sizes
#define numM2Adj 11
#define numM2Thm 63
#define numM2Typ 37
#define numM2Wth 19

// Mode 3: Indie Video Game - array sizes
#define numM3Adj 19
#define numM3Thm 71
#define numM3Typ 32
#define numM3For 12

#define DEBOUNCE 20  // button debouncer, how many ms to debounce, 5+ ms is usually plenty

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// set input pin numbers:
const int activatePin = 8;
const int selectPin = 9;

// variables for tracking input buttons
int activateState = 0;											// stores the activate button status
int selectState = 0;											// stores the select button status
int currentMode = 1;											// stores the current mode
boolean modeDisplayed = false;									// tracks through the menus
volatile int buttonPress = 0;									// GLOBAL: 0 = no button, 1 = activate button, 2 = select button
volatile unsigned long bounceTime = 0;							// holds ms count to debounce a pressed switch
int phraseLength = 0;											// tracks the phrase length
int currentWord = 0;											// tracks the current word in a phrase
char phraseArray[8][17];										// the current phrase one line at a time
String currentPhrase;											// the current phrase all at once for parsing
int thisSpace;													// stores location of current space when parsing phrase for display
int prevSpace;													// stores location of previous space when parsing phrase
int startIndexAt;												// stores current index location in phrase when parsing
int thisRand;													// used to avoid duplication when drawing words from the same list
int nextRand;													// used to avoid duplication when drawing words from the same list

// custom LCD characters for the 2-line META splash screen
byte Mtop[8] = {
	B10001,
	B11011,
	B11011,
	B10101,
	B10101,
	B10101,
	B10101,
	B10101
};

byte Mbottom[8] = {
	B10101,
	B10101,
	B10101,
	B10101,
	B10101,
	B10101,
	B10101,
	B10101
};

byte Etop[8] = {
	B11111,
	B11110,
	B10000,
	B10000,
	B10000,
	B10000,
	B10000,
	B11110
};

byte Ebottom[8] = {
	B11110,
	B10000,
	B10000,
	B10000,
	B10000,
	B10000,
	B11110,
	B11111
};

byte Ttop[8] = {
	B11111,
	B11111,
	B00100,
	B00100,
	B00100,
	B00100,
	B00100,
	B00100
};

byte Tbottom[8] = {
	B00100,
	B00100,
	B00100,
	B00100,
	B00100,
	B00100,
	B00100,
	B00100
};

byte Atop[8] = {
	B00100,
	B00100,
	B01010,
	B01010,
	B01010,
	B01010,
	B01010,
	B01010
};

byte Abottom[8] = {
	B11111,
	B10001,
	B10001,
	B10001,
	B10001,
	B10001,
	B10001,
	B10001
};

void setup() {
	lcd.createChar(0, Mtop);
	lcd.createChar(1, Mbottom);
	lcd.createChar(2, Etop);
	lcd.createChar(3, Ebottom);
	lcd.createChar(4, Ttop);
	lcd.createChar(5, Tbottom);
	lcd.createChar(6, Atop);
	lcd.createChar(7, Abottom);

	// initialize the button pins as inputs:
	pinMode(activatePin, INPUT); 
	pinMode(selectPin, INPUT); 
	// set up the LCD's number of columns and rows: 
	lcd.begin(16,2);
	// initialize the random number generator
	randomSeed(analogRead(0));
	
	// initialize Timer1
	cli();          // disable global interrupts
	TCCR1A = 0;     // set entire TCCR1A register to 0
	TCCR1B = 0;     // same for TCCR1B

	// set compare match register to desired timer count:
	OCR1A = 390;	// 25ms timer interrupt
	// turn on CTC mode:
	TCCR1B |= (1 << WGM12);
	// Set CS10 and CS12 bits for 1024 prescaler:
	TCCR1B |= (1 << CS10);
	TCCR1B |= (1 << CS12);
	// enable timer compare interrupt:
	TIMSK1 |= (1 << OCIE1A);
	sei();          // enable global interrupts
}

ISR(TIMER1_COMPA_vect) {
	check_buttons();
}

void check_buttons() {
	if(buttonPress == 0) {										// if there isn't already a pending button press
		// check for a button input
		activateState = digitalRead(activatePin);				// read the state of the activate button
		selectState = digitalRead(selectPin);					// read the state of the select button
		if(activateState == HIGH) {
			if(millis() > bounceTime) {
				buttonPress = 1;
				bounceTime = millis() + DEBOUNCE;				// set whatever bounce time in ms is appropriate
			}
		} else if(selectState == HIGH) {
			if(millis() > bounceTime) {
				buttonPress = 2;
				bounceTime = millis() + DEBOUNCE;				// set whatever bounce time in ms is appropriate
			}
		} else {
		}
	}
}

void loop() {
	// display the splash screen
	lcd.setCursor(6, 0);										// set the cursor to the 6th space in the first row
	lcd.write(byte(0));											// print the special char in space 0
	lcd.print("\x02\x04\x06");									// print the special chars in spaces 2,4,6
	lcd.setCursor(6, 1);										// set the cursor to the 6th space in the second row
	lcd.print("\x01\x03\x05\x07");								// print the special chars in spaces 1,3,5,7

	while (buttonPress == 0) {
		// loop until a button is pressed
	}

	// we broke out of the loop so let's check which button was pressed
	while(1) {
		// if button was "activate"
		if(buttonPress == 1) {									// check activate button status first
			switch(currentMode) {
				case 1:
					// display this mode's splash screen

					lcd.clear();								// clear screen
					lcd.setCursor(4, 0);						// set the cursor to the 5th space in the first row
					lcd.print("You will");						// screen line 1
					lcd.setCursor(0, 1);						// set the cursor to the 1st space in the second row
					lcd.print("Kickstart the...");				// screen line 2
					delay(2500);								// pause for a time

					// now generate a phrase from the current mode

					// generate the first adjective
					thisRand = random()%numAdj1;
					strcpy_P(buffer, (char*)pgm_read_word(&(adj_table[thisRand])));
					currentPhrase = String(buffer);
					// 1 in 2 chance of also generating a second adjective
					if(random(0,10) >= 5) {
						nextRand = random()%numAdj2;
						if(thisRand != nextRand) {				// make sure we don't print the same word twice
							strcpy_P(buffer, (char*)pgm_read_word(&(adj_table[nextRand])));
							currentPhrase += " ";
							currentPhrase += String(buffer);
						}
					}
					// generate the material
					strcpy_P(buffer, (char*)pgm_read_word(&(mat_table[random()%numMat])));
					currentPhrase += " ";
					currentPhrase += String(buffer);
					// generate the noun
					strcpy_P(buffer, (char*)pgm_read_word(&(noun_table[random()%numNouns])));
					currentPhrase += " ";
					currentPhrase += String(buffer);
					// chance of also generating a "for _____" suffix
					if(random(0,10) >= 7) {
						strcpy_P(buffer, (char*)pgm_read_word(&(for_table[random()%numFors])));
						currentPhrase += " ";
						currentPhrase += String(buffer);
					}
				break;
				
				case 2:
					// display this mode's splash screen

					lcd.clear();								// clear screen
					lcd.setCursor(0, 0);						// set the cursor to the 1st space in the first row
					lcd.print("Board game geeks");				// screen line 1
					lcd.setCursor(0, 1);						// set the cursor to the 1st space in the second row
					lcd.print(" will love your:");				// screen line 2
					delay(2500);								// pause for a time

					// now generate a phrase from the current mode

					currentPhrase = "";							// clear the current phrase
					// chance of generating a board game adjective
					if(random(0,10) >= 8) {
						strcpy_P(buffer, (char*)pgm_read_word(&(M2_adj_table[random()%numM2Adj])));
						currentPhrase += String(buffer);
						currentPhrase += " ";
					}
					// generate the board game theme
					thisRand = random()%numM2Thm;
					strcpy_P(buffer, (char*)pgm_read_word(&(M2_thm_table[thisRand])));
					currentPhrase += String(buffer);
					// 1 in 2 chance of also generating a second board game theme
					if(random(0,10) >= 5) {
						nextRand = random()%numM2Thm;
						if(thisRand != nextRand) {				// make sure we don't print the same word twice
							strcpy_P(buffer, (char*)pgm_read_word(&(M2_thm_table[nextRand])));
							currentPhrase += " ";
							currentPhrase += String(buffer);
						}
					}
					// generate the board game type
					strcpy_P(buffer, (char*)pgm_read_word(&(M2_typ_table[random()%numM2Typ])));
					currentPhrase += " ";
					currentPhrase += String(buffer);
					currentPhrase += " ";
					currentPhrase += "Game";
					// chance of also generating a "with _____" suffix
					if(random(0,10) >= 8) {
						strcpy_P(buffer, (char*)pgm_read_word(&(M2_wth_table[random()%numM2Wth])));
						currentPhrase += " with ";
						currentPhrase += String(buffer);
					}
				break;
				
				case 3:
					// display this mode's splash screen

					lcd.clear();								// clear screen
					lcd.setCursor(0, 0);						// set the cursor to the 1st space in the first row
					lcd.print("You're so indie,");				// screen line 1
					lcd.setCursor(0, 1);						// set the cursor to the 1st space in the second row
					lcd.print("You'll make the:");				// screen line 2
					delay(2500);								// pause for a time
					// now generate a phrase from the current mode

					currentPhrase = "";							// clear the current phrase
					// chance of generating a video game adjective
					if(random(0,10) >= 8) {
						strcpy_P(buffer, (char*)pgm_read_word(&(M3_adj_table[random()%numM3Adj])));
						currentPhrase += String(buffer);
						currentPhrase += " ";
					}
					// generate the video game theme
					thisRand = random()%numM3Thm;
					strcpy_P(buffer, (char*)pgm_read_word(&(M3_thm_table[thisRand])));
					currentPhrase += String(buffer);
					// 1 in 2 chance of also generating a second video game theme
					if(random(0,10) >= 5) {
						nextRand = random()%numM3Thm;
						if(thisRand != nextRand) {				// make sure we don't print the same word twice
							strcpy_P(buffer, (char*)pgm_read_word(&(M3_thm_table[nextRand])));
							currentPhrase += " ";
							currentPhrase += String(buffer);
						}
					}
					// generate the video game type
					thisRand = random()%numM3Typ;
					strcpy_P(buffer, (char*)pgm_read_word(&(M3_typ_table[thisRand])));
					currentPhrase += " ";
					currentPhrase += String(buffer);
					// 1 in 2 chance of also generating a second video game type
					if(random(0,10) >= 5) {
						nextRand = random()%numM3Typ;
						if(thisRand != nextRand) {				// make sure we don't print the same word twice
							strcpy_P(buffer, (char*)pgm_read_word(&(M3_typ_table[nextRand])));
							currentPhrase += " ";
							currentPhrase += String(buffer);
						}
					}
					currentPhrase += " ";
					currentPhrase += "Game";
					// chance of also generating a "for _____" suffix
					if(random(0,10) >= 8) {
						strcpy_P(buffer, (char*)pgm_read_word(&(M3_for_table[random()%numM3For])));
						currentPhrase += " for ";
						currentPhrase += String(buffer);
					}
				break;
			}

			// this [new] version appends each generated portion of the phrase into the currentPhrase string
				// then parses the string to make segments <= 16 characters
				// then displays each segment on its own line

			buttonPress = 0;
			modeDisplayed = false;
			// display the phrase one line at a time and loop until another button press

			phraseLength = 1;
			do {
				startIndexAt = 0;
				thisSpace = 0;
				prevSpace = 0;
				do {
					// get the index of the next space
					thisSpace = currentPhrase.indexOf(' ',startIndexAt);
					if(thisSpace <= 16 && thisSpace != -1) {
						startIndexAt = thisSpace+1;
						prevSpace = thisSpace;
					}
				} while (thisSpace <= 16 && thisSpace != -1);
				currentPhrase.substring(0,prevSpace).toCharArray(phraseArray[phraseLength-1],17);
				currentPhrase = currentPhrase.substring(prevSpace+1);
				phraseLength++;
			} while (currentPhrase.length() > 16);
			currentPhrase.toCharArray(phraseArray[phraseLength-1],17);
			// we now have the phrase to display in an array (phraseArray) with each line <= 16 characters

			lcd.clear();										// clear screen
			do {
				currentWord = 0;
				lcd.setCursor(0, 0);							// set the cursor to (0,0)
				lcd.print(phraseArray[currentWord]);			// print the word
				currentWord++;									// increment to the next word
				lcd.setCursor(0, 1);							// set the cursor to (0,1)
				lcd.print(phraseArray[currentWord]);			// print the word
				if(delay_with_break(1500)) {					// pause for a time
					break;
				}
				while(currentWord < phraseLength-1) {
					lcd.clear();								// clear screen
					lcd.setCursor(0, 0);						// set the cursor to (0,0)
					lcd.print(phraseArray[currentWord]);		// print the word
					currentWord++;								// increment to the next word
					lcd.setCursor(0, 1);						// set the cursor to (0,1)
					lcd.print(phraseArray[currentWord]);		// print the word
					if(delay_with_break(1500)) {					// pause for a time
						break;
					}
				}
				if(phraseLength > 2) {
					lcd.clear();								// clear screen
					if(delay_with_break(250)) {					// pause for a time
						break;
					}
				}
			} while (buttonPress == 0);

		// if button was "select"
		} else if (buttonPress == 2) {							// check select button next
			if(modeDisplayed == true) {
				currentMode++;
				if(currentMode > 3) {
					currentMode = 1;
				}
			}
			// display the current mode on-screen
			switch(currentMode) {
				case 1:
					lcd.clear();								// clear screen
					lcd.setCursor(4, 0);						// set the cursor to the 4th space in the first row
					lcd.print("Mode 1:");						// screen line 1
					lcd.setCursor(2, 1);						// set the cursor to the 2nd space in the second row
					lcd.print("Kickstarter");					// screen line 2
					delay(500);									// pause for a time
					modeDisplayed = true;
					buttonPress = 0;
				break;
				case 2:
					lcd.clear();								// clear screen
					lcd.setCursor(4, 0);						// set the cursor to the 4th space in the first row
					lcd.print("Mode 2:");						// screen line 1
					lcd.setCursor(3, 1);						// set the cursor to the 2nd space in the second row
					lcd.print("Board Game");					// screen line 2
					delay(500);									// pause for a time
					modeDisplayed = true;
					buttonPress = 0;
				break;
				case 3:
					lcd.clear();								// clear screen
					lcd.setCursor(4, 0);						// set the cursor to the 4th space in the first row
					lcd.print("Mode 3:");						// screen line 1
					lcd.setCursor(0, 1);						// set the cursor to the 2nd space in the second row
					lcd.print("Indie Video Game");					// screen line 2
					delay(500);									// pause for a time
					modeDisplayed = true;
					buttonPress = 0;
				break;
			}
			// cycle through the modes on screen
		} else {
			// do nothing
		}
	}
};

boolean delay_with_break(int ms) {
	for(int i=0; i <= (ms/100); i++) {
		delay(100);
		if(buttonPress != 0) {
			return true;
		}
	}
	return false;
};