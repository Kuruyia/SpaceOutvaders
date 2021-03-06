/**
 * @file screen_id_map.cpp
 * @brief Fournit un mapping entre un ScreenIdentifiers et une classe dérivée d'IScreen
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 09 janvier 2020
 */

#include "screen_id_map.h"

#include "config_utility.h"
#include "end_game.h"
#include "main_game.h"
#include "title_menu.h"
#include "top_scores.h"

#include "../tools/myexception.h"

#define SCREENIDMAP nsScreen::ScreenIdMap

std::unique_ptr<nsScreen::IScreen> SCREENIDMAP::getScreenFromId(const nsScreen::ScreenIdentifiers &screenId)
{
    // Check the ID and return the right Screen
    switch (screenId)
    {
        case ScreenIdentifiers::ID_TitleMenu:
            return std::unique_ptr<IScreen>(new nsScreen::TitleMenu());
        case ScreenIdentifiers::ID_MainGame:
            return std::unique_ptr<IScreen>(new nsScreen::MainGame());
        case ScreenIdentifiers::ID_EndGame:
            return std::unique_ptr<IScreen>(new nsScreen::EndGame());
        case ScreenIdentifiers::ID_TopScores:
            return std::unique_ptr<IScreen>(new nsScreen::TopScores());
        case ScreenIdentifiers::ID_Config:
            return std::unique_ptr<IScreen>(new nsScreen::ConfigUtility());
        case ScreenIdentifiers::ID_None:
        default:
            throw MyException(nsUtil::kScreenNotFound);
    }
} // getScreenFromId()

#undef SCREENIDMAP
