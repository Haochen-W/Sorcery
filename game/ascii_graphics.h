#include <vector>
#include <string>

//SIMPLE_GRAPHICS = 0 displays a fancy style.
//SIMPLE_GRAPHICS = 1 displays the style shown in the project specification's examples
//You are encouraged to use SIMPLE_GRAPHICS = 0, but some terminals may not like it.
#define SIMPLE_GRAPHICS 0

typedef std::vector<std::string> card_template_t;

card_template_t display_minion_no_ability(std::string name,int cost,int attack,int defence);
card_template_t display_minion_triggered_ability(std::string name,int cost,int attack,int defence,
                                                 std::string trigger_desc);
card_template_t display_minion_activated_ability(std::string name,int cost,int attack,int defence,
                                                 int ability_cost, std::string ability_desc);
card_template_t display_ritual(std::string name,int cost,int ritual_cost,std::string ritual_desc,
                               int ritual_charges);
card_template_t display_spell(std::string name,int cost,std::string desc);
card_template_t display_enchantment_attack_defence(std::string name,int cost,std::string desc,
                                                   std::string attack,std::string defence);
card_template_t display_enchantment(std::string name,int cost,std::string desc);
card_template_t display_player_card(int player_num,std::string name,int life,int mana);

extern const card_template_t CARD_TEMPLATE_MINION_NO_ABILITY;
extern const card_template_t CARD_TEMPLATE_MINION_WITH_ABILITY;
extern const card_template_t CARD_TEMPLATE_BORDER;
extern const card_template_t CARD_TEMPLATE_EMPTY;
extern const card_template_t CARD_TEMPLATE_RITUAL;
extern const card_template_t CARD_TEMPLATE_SPELL;
extern const card_template_t CARD_TEMPLATE_ENCHANTMENT_WITH_ATTACK_DEFENCE;
extern const card_template_t CARD_TEMPLATE_ENCHANTMENT;

extern const card_template_t PLAYER_1_TEMPLATE;
extern const card_template_t PLAYER_2_TEMPLATE;

extern const std::vector<std::string> CENTRE_GRAPHIC;

extern const std::string EXTERNAL_BORDER_CHAR_UP_DOWN;
extern const std::string EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
extern const std::string EXTERNAL_BORDER_CHAR_TOP_LEFT;
extern const std::string EXTERNAL_BORDER_CHAR_TOP_RIGHT;
extern const std::string EXTERNAL_BORDER_CHAR_BOTTOM_LEFT;
extern const std::string EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT;
