#include "Draw.h"

int width = 1000;
int height = 1000;
bool do_once = true;

PDIRECT3DTEXTURE9 two_clubs_tex = NULL;
PDIRECT3DTEXTURE9 two_diamonds_tex = NULL;
PDIRECT3DTEXTURE9 two_hearts_tex = NULL;
PDIRECT3DTEXTURE9 two_spades_tex = NULL;
PDIRECT3DTEXTURE9 three_clubs_tex = NULL;
PDIRECT3DTEXTURE9 three_diamonds_tex = NULL;
PDIRECT3DTEXTURE9 three_hearts_tex = NULL;
PDIRECT3DTEXTURE9 three_spades_tex = NULL;
PDIRECT3DTEXTURE9 four_clubs_tex = NULL;
PDIRECT3DTEXTURE9 four_diamonds_tex = NULL;
PDIRECT3DTEXTURE9 four_hearts_tex = NULL;
PDIRECT3DTEXTURE9 four_spades_tex = NULL;
PDIRECT3DTEXTURE9 five_clubs_tex = NULL;
PDIRECT3DTEXTURE9 five_diamonds_tex = NULL;
PDIRECT3DTEXTURE9 five_hearts_tex = NULL;
PDIRECT3DTEXTURE9 five_spades_tex = NULL;
PDIRECT3DTEXTURE9 six_clubs_tex = NULL;
PDIRECT3DTEXTURE9 six_diamonds_tex = NULL;
PDIRECT3DTEXTURE9 six_hearts_tex = NULL;
PDIRECT3DTEXTURE9 six_spades_tex = NULL;
PDIRECT3DTEXTURE9 seven_clubs_tex = NULL;
PDIRECT3DTEXTURE9 seven_diamonds_tex = NULL;
PDIRECT3DTEXTURE9 seven_hearts_tex = NULL;
PDIRECT3DTEXTURE9 seven_spades_tex = NULL;
PDIRECT3DTEXTURE9 eight_clubs_tex = NULL;
PDIRECT3DTEXTURE9 eight_diamonds_tex = NULL;
PDIRECT3DTEXTURE9 eight_hearts_tex = NULL;
PDIRECT3DTEXTURE9 eight_spades_tex = NULL;
PDIRECT3DTEXTURE9 nine_clubs_tex = NULL;
PDIRECT3DTEXTURE9 nine_diamonds_tex = NULL;
PDIRECT3DTEXTURE9 nine_hearts_tex = NULL;
PDIRECT3DTEXTURE9 nine_spades_tex = NULL;
PDIRECT3DTEXTURE9 ten_clubs_tex = NULL;
PDIRECT3DTEXTURE9 ten_diamonds_tex = NULL;
PDIRECT3DTEXTURE9 ten_hearts_tex = NULL;
PDIRECT3DTEXTURE9 ten_spades_tex = NULL;
PDIRECT3DTEXTURE9 jack_clubs_tex = NULL;
PDIRECT3DTEXTURE9 jack_diamonds_tex = NULL;
PDIRECT3DTEXTURE9 jack_hearts_tex = NULL;
PDIRECT3DTEXTURE9 jack_spades_tex = NULL;
PDIRECT3DTEXTURE9 queen_clubs_tex = NULL;
PDIRECT3DTEXTURE9 queen_diamonds_tex = NULL;
PDIRECT3DTEXTURE9 queen_hearts_tex = NULL;
PDIRECT3DTEXTURE9 queen_spades_tex = NULL;
PDIRECT3DTEXTURE9 king_clubs_tex = NULL;
PDIRECT3DTEXTURE9 king_diamonds_tex = NULL;
PDIRECT3DTEXTURE9 king_hearts_tex = NULL;
PDIRECT3DTEXTURE9 king_spades_tex = NULL;
PDIRECT3DTEXTURE9 ace_clubs_tex = NULL;
PDIRECT3DTEXTURE9 ace_diamonds_tex = NULL;
PDIRECT3DTEXTURE9 ace_hearts_tex = NULL;
PDIRECT3DTEXTURE9 ace_spades_tex = NULL;
PDIRECT3DTEXTURE9 blank_tex = NULL;
PDIRECT3DTEXTURE9 back_tex = NULL;

// Simple helper function to load an image into a DX9 texture with common settings
bool LoadTextureFromMemory(LPDIRECT3DDEVICE9 device, const unsigned char* data, int size, PDIRECT3DTEXTURE9* out_texture, int* out_width, int* out_height)
{
    PDIRECT3DTEXTURE9 texture;
    HRESULT hr = D3DXCreateTextureFromFileInMemoryEx(device, data, size, 300, 100, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &texture);
    if (hr != S_OK)
        return false;

    // Retrieve description of the texture surface so we can access its size
    D3DSURFACE_DESC my_image_desc;
    texture->GetLevelDesc(0, &my_image_desc);
    *out_texture = texture;
    *out_width = (int)my_image_desc.Width;
    *out_height = (int)my_image_desc.Height;
    return true;
}

PDIRECT3DTEXTURE9 LoadImageFromMemory(LPDIRECT3DDEVICE9 device, const unsigned char* data, int size)
{
    PDIRECT3DTEXTURE9 my_texture;
    int my_image_width = 0;
    int my_image_height = 0;
    bool ret = LoadTextureFromMemory(device, data, size, &my_texture, &my_image_width, &my_image_height);
    IM_ASSERT(ret);

    return my_texture;
}

void DrawImageFromMemory(LPDIRECT3DDEVICE9 device, PDIRECT3DTEXTURE9 my_texture, const unsigned char* data, int size, int width, int height)
{
    int my_image_width = 0;
    int my_image_height = 0;
    bool ret = LoadTextureFromMemory(device, data, size, &my_texture, &my_image_width, &my_image_height);
    IM_ASSERT(ret);

    ImGui::Image((void*)my_texture, ImVec2(width, height));
}

void LoadImages(LPDIRECT3DDEVICE9 device)
{
    two_clubs_tex = LoadImageFromMemory(device, two_clubs_png, sizeof(two_clubs_png));
    two_diamonds_tex = LoadImageFromMemory(device, two_diamonds_png, sizeof(two_diamonds_png));
    two_hearts_tex = LoadImageFromMemory(device, two_hearts_png, sizeof(two_hearts_png));
    two_spades_tex = LoadImageFromMemory(device, two_spades_png, sizeof(two_spades_png));
    three_clubs_tex = LoadImageFromMemory(device, three_clubs_png, sizeof(three_clubs_png));
    three_diamonds_tex = LoadImageFromMemory(device, three_diamonds_png, sizeof(three_diamonds_png));
    three_hearts_tex = LoadImageFromMemory(device, three_hearts_png, sizeof(three_hearts_png));
    three_spades_tex = LoadImageFromMemory(device, three_spades_png, sizeof(three_spades_png));
    four_clubs_tex = LoadImageFromMemory(device, four_clubs_png, sizeof(four_clubs_png));
    four_diamonds_tex = LoadImageFromMemory(device, four_diamonds_png, sizeof(four_diamonds_png));
    four_hearts_tex = LoadImageFromMemory(device, four_hearts_png, sizeof(four_hearts_png));
    four_spades_tex = LoadImageFromMemory(device, four_spades_png, sizeof(four_spades_png));
    five_clubs_tex = LoadImageFromMemory(device, five_clubs_png, sizeof(five_clubs_png));
    five_diamonds_tex = LoadImageFromMemory(device, five_diamonds_png, sizeof(five_diamonds_png));
    five_hearts_tex = LoadImageFromMemory(device, five_hearts_png, sizeof(five_hearts_png));
    five_spades_tex = LoadImageFromMemory(device, five_spades_png, sizeof(five_spades_png));
    six_clubs_tex = LoadImageFromMemory(device, six_clubs_png, sizeof(six_clubs_png));
    six_diamonds_tex = LoadImageFromMemory(device, six_diamonds_png, sizeof(six_diamonds_png));
    six_hearts_tex = LoadImageFromMemory(device, six_hearts_png, sizeof(six_hearts_png));
    six_spades_tex = LoadImageFromMemory(device, six_spades_png, sizeof(six_spades_png));
    seven_clubs_tex = LoadImageFromMemory(device, seven_clubs_png, sizeof(seven_clubs_png));
    seven_diamonds_tex = LoadImageFromMemory(device, seven_diamonds_png, sizeof(seven_diamonds_png));
    seven_hearts_tex = LoadImageFromMemory(device, seven_hearts_png, sizeof(seven_hearts_png));
    seven_spades_tex = LoadImageFromMemory(device, seven_spades_png, sizeof(seven_spades_png));
    eight_clubs_tex = LoadImageFromMemory(device, eight_clubs_png, sizeof(eight_clubs_png));
    eight_diamonds_tex = LoadImageFromMemory(device, eight_diamonds_png, sizeof(eight_diamonds_png));
    eight_hearts_tex = LoadImageFromMemory(device, eight_hearts_png, sizeof(eight_hearts_png));
    eight_spades_tex = LoadImageFromMemory(device, eight_spades_png, sizeof(eight_spades_png));
    nine_clubs_tex = LoadImageFromMemory(device, nine_clubs_png, sizeof(nine_clubs_png));
    nine_diamonds_tex = LoadImageFromMemory(device, nine_diamonds_png, sizeof(nine_diamonds_png));
    nine_hearts_tex = LoadImageFromMemory(device, nine_hearts_png, sizeof(nine_hearts_png));
    nine_spades_tex = LoadImageFromMemory(device, nine_spades_png, sizeof(nine_spades_png));
    ten_clubs_tex = LoadImageFromMemory(device, ten_clubs_png, sizeof(ten_clubs_png));
    ten_diamonds_tex = LoadImageFromMemory(device, ten_diamonds_png, sizeof(ten_diamonds_png));
    ten_hearts_tex = LoadImageFromMemory(device, ten_hearts_png, sizeof(ten_hearts_png));
    ten_spades_tex = LoadImageFromMemory(device, ten_spades_png, sizeof(ten_spades_png));
    jack_clubs_tex = LoadImageFromMemory(device, jack_clubs_png, sizeof(jack_clubs_png));
    jack_diamonds_tex = LoadImageFromMemory(device, jack_diamonds_png, sizeof(jack_diamonds_png));
    jack_hearts_tex = LoadImageFromMemory(device, jack_hearts_png, sizeof(jack_hearts_png));
    jack_spades_tex = LoadImageFromMemory(device, jack_spades_png, sizeof(jack_spades_png));
    queen_clubs_tex = LoadImageFromMemory(device, queen_clubs_png, sizeof(queen_clubs_png));
    queen_diamonds_tex = LoadImageFromMemory(device, queen_diamonds_png, sizeof(queen_diamonds_png));
    queen_hearts_tex = LoadImageFromMemory(device, queen_hearts_png, sizeof(queen_hearts_png));
    queen_spades_tex = LoadImageFromMemory(device, queen_spades_png, sizeof(queen_spades_png));
    king_clubs_tex = LoadImageFromMemory(device, king_clubs_png, sizeof(king_clubs_png));
    king_diamonds_tex = LoadImageFromMemory(device, king_diamonds_png, sizeof(king_diamonds_png));
    king_hearts_tex = LoadImageFromMemory(device, king_hearts_png, sizeof(king_hearts_png));
    king_spades_tex = LoadImageFromMemory(device, king_spades_png, sizeof(king_spades_png));
    ace_clubs_tex = LoadImageFromMemory(device, ace_clubs_png, sizeof(ace_clubs_png));
    ace_diamonds_tex = LoadImageFromMemory(device, ace_diamonds_png, sizeof(ace_diamonds_png));
    ace_hearts_tex = LoadImageFromMemory(device, ace_hearts_png, sizeof(ace_hearts_png));
    ace_spades_tex = LoadImageFromMemory(device, ace_spades_png, sizeof(ace_spades_png));
    blank_tex = LoadImageFromMemory(device, blank_png, sizeof(blank_png));
    back_tex = LoadImageFromMemory(device, back_png, sizeof(back_png));
}

PDIRECT3DTEXTURE9 GetCardTexture(LPDIRECT3DDEVICE9 device, int number, int type)
{
    switch (number)
    {

    case 2: switch (type)
    {
    case 99:  return two_clubs_tex;
    case 100: return two_diamonds_tex;
    case 104: return two_hearts_tex;
    case 115: return two_spades_tex;
    };

    case 3: switch (type)
    {
    case 99:  return three_clubs_tex;
    case 100: return three_diamonds_tex;
    case 104: return three_hearts_tex;
    case 115: return three_spades_tex;
    };

    case 4: switch (type)
    {
    case 99:  return four_clubs_tex;
    case 100: return four_diamonds_tex;
    case 104: return four_hearts_tex;
    case 115: return four_spades_tex;
    };

    case 5: switch (type)
    {
    case 99:  return five_clubs_tex;
    case 100: return five_diamonds_tex;
    case 104: return five_hearts_tex;
    case 115: return five_spades_tex;
    };

    case 6: switch (type)
    {
    case 99:  return six_clubs_tex;
    case 100: return six_diamonds_tex;
    case 104: return six_hearts_tex;
    case 115: return six_spades_tex;
    };

    case 7: switch (type)
    {
    case 99:  return seven_clubs_tex;
    case 100: return seven_diamonds_tex;
    case 104: return seven_hearts_tex;
    case 115: return seven_spades_tex;
    };

    case 8: switch (type)
    {
    case 99:  return eight_clubs_tex;
    case 100: return eight_diamonds_tex;
    case 104: return eight_hearts_tex;
    case 115: return eight_spades_tex;
    };

    case 9: switch (type)
    {
    case 99:  return nine_clubs_tex;
    case 100: return nine_diamonds_tex;
    case 104: return nine_hearts_tex;
    case 115: return nine_spades_tex;
    };

    case 10: switch (type)
    {
    case 99:  return ten_clubs_tex;
    case 100: return ten_diamonds_tex;
    case 104: return ten_hearts_tex;
    case 115: return ten_spades_tex;
    };

    case 11: switch (type)
    {
    case 99:  return jack_clubs_tex;
    case 100: return jack_diamonds_tex;
    case 104: return jack_hearts_tex;
    case 115: return jack_spades_tex;
    };

    case 12: switch (type)
    {
    case 99:  return queen_clubs_tex;
    case 100: return queen_diamonds_tex;
    case 104: return queen_hearts_tex;
    case 115: return queen_spades_tex;
    };

    case 13: switch (type)
    {
    case 99:  return king_clubs_tex;
    case 100: return king_diamonds_tex;
    case 104: return king_hearts_tex;
    case 115: return king_spades_tex;
    };

    case 14: switch (type)
    {
    case 99:  return ace_clubs_tex;
    case 100: return ace_diamonds_tex;
    case 104: return ace_hearts_tex;
    case 115: return ace_spades_tex;
    };

    default: return back_tex;
    }
}

void DrawTableInfo(LPDIRECT3DDEVICE9 g_pd3dDevice, uint32_t table, uint32_t table_client_data, char* table_name)
{
    std::vector<Player> players;
    std::vector<Card> cards;

    uint32_t player_offset = 0xC08;
    uint32_t player_size = 0x1F8;

    uint32_t cards_on_display_count = mem->Read<uint32_t>(table_client_data + 0xB50);
    uint32_t pot_size = mem->Read<uint32_t>(table_client_data + 0x234);

    uint32_t dealer_player_id = mem->Read<uint32_t>(table + 0xF20);
    uint32_t current_player_id = mem->Read<uint32_t>(table + 0xF24);

    ImGui::Columns(2, "Info", false);

    ImGui::Text("Table Name: %s", table_name);

    ImGui::Text("Cards: %i", cards_on_display_count);
    ImGui::Text("Pot: %i", pot_size);

    ImGui::Text("Dealer Player ID: %i", dealer_player_id);
    ImGui::Text("Current Player ID: %i", current_player_id);

    uint32_t ante = mem->Read<uint32_t>(table_client_data + 0x298);
    uint32_t small_blind = mem->Read<uint32_t>(table_client_data + 0xEC);
    uint32_t big_blind = mem->Read<uint32_t>(table_client_data + 0xF0);

    ImGui::Text("Ante %i, Small Blind %i, Big Blind %i", ante, small_blind, big_blind);

    ImGui::NextColumn();

    for (int i = 0; i < 5; i++) {
        uint32_t card_address = (table_client_data + 0xB5C) + (0x8 * i);

        Card card(mem, card_address);

        ImGui::Image((void*)GetCardTexture(g_pd3dDevice, card.number, card.type), ImVec2(134 / 3, 186 / 3));

        if (i != 4)
            ImGui::SameLine();

        cards.push_back(card);
    }

    ImGui::Columns(1);
    

    ImGui::Columns(7, "mycolumns");
    ImGui::Separator();
    ImGui::Text("ID"); ImGui::NextColumn();
    ImGui::Text("Name"); ImGui::NextColumn();
    ImGui::Text("Amount"); ImGui::NextColumn();
    ImGui::Text("Current Bet"); ImGui::NextColumn();
    ImGui::Text("Total Bet"); ImGui::NextColumn();
    ImGui::Text("Total"); ImGui::NextColumn();
    ImGui::Text("State"); ImGui::NextColumn();
    ImGui::Separator();

    for (int i = 0; i < 9; i++)
    {
        uint32_t player_address = (table_client_data + 0xC08) + (player_size * i);

        Player player(mem, player_address, i);

        if (!player.IsValid())
            continue;

        players.push_back(player);

        if (dealer_player_id == i) {
            ImGui::Text("%i D", i);
        }
        else if (dealer_player_id + 1 == i)
        {
            ImGui::Text("%i SB", i);
        }
        else if (dealer_player_id + 2 == i)
        {
            ImGui::Text("%i BB", i);
        }
        else {
            ImGui::Text("%i", i);
        }
        ImGui::NextColumn();

        ImGui::Text("%s", player.name);

        ImGui::Image((void*)GetCardTexture(g_pd3dDevice, player.first_card_number, player.first_card_type), ImVec2(134 / 6, 186 / 6));
        ImGui::SameLine();
        ImGui::Image((void*)GetCardTexture(g_pd3dDevice, player.second_card_number, player.second_card_type), ImVec2(134 / 6, 186 / 6));
        ImGui::NextColumn();

        ImGui::Text("%i", player.chip_size);
        ImGui::NextColumn();

        ImGui::Text("%i", player.bet_amount);
        ImGui::NextColumn();

        ImGui::Text("%i", player.bet_total);
        ImGui::NextColumn();

        ImGui::Text("%i", player.chip_size + player.bet_amount);
        ImGui::NextColumn();

        ImGui::Text("%s", player.state == 1 ? "OUT" : "IN");
        ImGui::NextColumn();
    }

    /*
    std::string player_name = "greenarr0528";

    auto it = std::find_if(players.begin(), players.end(), [&player_name](const Player& obj) {return obj.name == player_name; });

    if (it != players.end())
    {
        auto index = std::distance(players.begin(), it);

        Player current_player = players.at(index);

        if (current_player.first_card_number != 0 && current_player.second_card_number != 0)
        {
            std::string my_hand = pp_card(current_player.first_card_number, current_player.first_card_type) + pp_card(current_player.second_card_number, current_player.second_card_type);
            std::string table_hand;

            for (Card& card : cards)
            {
                if (card.number != 0)
                {
                    table_hand += pp_card(card.number, card.type);
                }
            }

            //printf("[my_hand] %s\n", my_hand.c_str());
            //printf("[table_hand] %s\n", table_hand.c_str());

            float equity = GetEquity(my_hand, players.size() - 1, table_hand);
            printf("[equity] %f\n", equity);
        }
    }
    */

    ImGui::Columns(1);
    ImGui::Separator();

    players.clear();
    cards.clear();
}

std::vector<uintptr_t> tables;

void Draw(LPDIRECT3DDEVICE9 g_pd3dDevice)
{
    std::vector<std::string> table_names;

    if (do_once) {
        LoadImages(g_pd3dDevice);
        //1f72f10 : fb2f10 : Table::LobbyTableData2
        tables = mem->FindReferences("\x10\x2F\xF7\x01\x01", "xxxxx", 100);
        do_once = false;
    }

    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(width, height), ImGuiCond_FirstUseEver);

    ImGui::Begin("##Backbuffer", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
    {
        ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
        if (ImGui::BeginTabBar("MyTabBar", tab_bar_flags))
        {
            for (auto& table : tables) {
                uintptr_t table_client_data = mem->Read<uintptr_t>(table - 0x14);

                char table_name[15];
                uint32_t table_name_ptr = mem->Read<uint32_t>(table_client_data + 0xC4);
                mem->ReadBuffer(table_name_ptr, &table_name, sizeof(table_name));

                if (std::find(table_names.begin(), table_names.end(), table_name) != table_names.end()) {
                    break;
                }
                else {
                    table_names.push_back(table_name);
                }

                if (ImGui::BeginTabItem(table_name))
                {
                    DrawTableInfo(g_pd3dDevice, table, table_client_data, table_name);

                    ImGui::EndTabItem();
                }
            }
            ImGui::EndTabBar();
        }
        table_names.empty();
    }
    ImGui::End();

    //bool show_demo_window = 1;
    //if (show_demo_window)
    //    ImGui::ShowDemoWindow(&show_demo_window);
}
