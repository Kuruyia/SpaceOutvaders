/**
  * @file main_game.h
  * @author PALATUIK Alison
  * @date 13 Janvier 2020
  * @brief Definition de l'écran de jeu principal
  * @version 1.0
  * @bug Aucun connu
  */

#ifndef SCREENGAME_H
#define SCREENGAME_H

#include "iscreen.h"

#include <iostream>

#include "../config/config.h"
#include "../figs/rectangle.h"
#include "../transition/transition_engine.h"

#include "../game/difficulty.hpp"
#include "../game/manager_type.h"

#include "../gui/button.h"
#include "../gui/sprite.h"
#include "../gui/text.h"

namespace nsScreen {

/**
 * @class MainGame
 * @brief Ecran représentant le jeu
 */
class MainGame : public IScreen
{
public:
    /**
     * @brief Constructeur pour la classe MainGame
     * @fn MainGame();
     */
    MainGame();

    /**
     * @brief Destructeur virtuel pour la classe MainGame
     * @fn virtual ~MainGame() {}
     */
    virtual ~MainGame() {}

    virtual void processEvent(const nsEvent::Event_t &event) override;
    virtual void update(const std::chrono::microseconds &delta) override;
    virtual void draw(MinGL &window) override;
    virtual std::unique_ptr<IDrawable> clone() const override;

private:
    /**
     * @brief m_configuration : Tableau de configuration de la partie
     */
    nsConfig::TableauCommande m_configuration;

    /**
     * @brief m_difficulty : Difficulté pour cette session de jeu
     */
    nsGame::Difficulty m_difficulty;

    /**
     * @brief m_deplacementEnnemi : Temps depuis le dernier déplacement ennemi
     */
    std::chrono::microseconds m_deplacementEnnemi;

    /**
     * @brief m_tir : Temps depuis le dernier tir ennemi
     */
    std::chrono::microseconds m_tir;

    /**
     * @brief m_tir : Temps depuis le dernier déplacement de missile
     */
    std::chrono::microseconds m_missile;

    /**
     * @brief m_freqDeplacementEnnemi : Fréquence de déplacement de l'ennemi
     */
    const std::chrono::milliseconds m_freqDeplacementEnnemi;

    /**
     * @brief m_freqTir : Fréquence de tir de l'ennemi
     */
    const std::chrono::milliseconds m_freqTir;

    /**
     * @brief m_freqDeplacementEnnemi : Fréquence de déplacement des missiles
     */
    const std::chrono::milliseconds m_freqMissile;

    /**
     * @brief m_ennemiDeplacementDroite : Flag set si les ennemis se déplacent a droite (pour le déplacement "naturel" des Invaders)
     */
    bool m_ennemiDeplacementDroite;

    /**
     * @brief m_vies : Nombre de vies restantes du joueur
     */
    unsigned m_vies;

    /**
     * @brief m_texteViesTitre : Titre du nombre de vies
     */
    nsGui::Text m_texteViesTitre;

    /**
     * @brief m_texteViesTitre : Texte du nombre de vies
     */
    nsGui::Text m_texteVies;

    /**
     * @brief m_score : Score du joueur
     */
    unsigned m_score;

    /**
     * @brief m_texteScoreTitre : Titre du score
     */
    nsGui::Text m_texteScoreTitre;

    /**
     * @brief m_textScore : Texte du score
     */
    nsGui::Text m_textScore;

    /**
     * @brief m_space : Aire de jeu
     */
    nsGame::CVString m_space;

    /**
     * @brief m_objects : Objets dans l'espace de jeu
     */
    nsGame::CAObject m_objects;

    /**
     * @brief m_shipSprite : Le sprite du vaisseau du joueur
     */
    nsGui::Sprite m_shipSprite;

    /**
     * @brief m_shipWeaponSprite : Le sprite du missile du joueur
     */
    nsGui::Sprite m_shipWeaponSprite;

    /**
     * @brief m_invaderSprite : Le sprite des envahisseurs
     */
    nsGui::Sprite m_invaderSprite;

    /**
     * @brief m_invaderWeaponSprite : Le sprite des torpilles des envahisseurs
     */
    nsGui::Sprite m_invaderWeaponSprite;

    /**
     * @brief Sauvegarde et quitte le jeu
     * @param[in] playerWon : Flag set si le joueur a gagné
     * @fn void saveAndExit(const bool &playerWon);
     */
    void saveAndExit(const bool &playerWon);

    /**
     * @brief Règle la difficulté selon la configuration
     * @fn void setDifficultyFromConfig();
     */
    void setDifficultyFromConfig();
};

} // namespace nsScreen

#endif // SCREENGAME_H
