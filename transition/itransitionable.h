/**
 * @file itransitionable.h
 * @brief Classe abstraite représentant un objet transitionable
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 10 janvier 2020
 */

#ifndef ITRANSITIONABLE_H
#define ITRANSITIONABLE_H

#include <vector>

namespace nsTransition
{

/**
 * @class ITransitionable
 * @brief Une classe abstraite pour n'importe quelle élément pouvant effectuer une transition entre deux états
 */
class ITransitionable
{
public:
    /**
     * @brief Destructeur pour la classe ITransitionable
     * @fn virtual ~ITransitionable() {}
     */
    virtual ~ITransitionable() {}

    /**
     * @brief Récupère des valeurs dans un vecteur de float pour l'ID spécifié
     * @param[in] id: ID des valeurs a récupérer
     * @param[in, out] values: Vecteur de valeurs a peupler
     * @fn virtual void getValues(const int &id, std::vector<float> &values);
     */
    virtual void getValues(const int &id, std::vector<float> &values) = 0;

    /**
     * @brief Définit les nouvelles valeurs pour l'ID spécifié
     * @param[in] id: ID des valeurs a définir
     * @param[in] values: Vecteur des nouvelles valeurs a appliquer
     * @fn virtual void setValues(const int &id, const std::vector<float> &values);
     */
    virtual void setValues(const int &id, const std::vector<float> &values) = 0;
};

} // namespace nsTransition

#endif // ITRANSITIONABLE_H
