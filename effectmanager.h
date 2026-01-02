#ifndef EFFECTMANAGER_H
#define EFFECTMANAGER_H

class CImmEffect;
class CImmProject;
class CImmDevice;

#include <QObject>
#include <QWindow>
#include <QMainWindow>
#include <vector>

class EffectManager : public QObject
{
    Q_OBJECT
public:
    explicit EffectManager(QObject *parent = 0);

    // Initialisation du manager
    bool initializeMouse(QWindow const& window);
    bool initializeMouse(QMainWindow const* window);

    // Ajout d'un nouvel effet qui s'additionnera au précédent.
    // Le dernier effet est supprimé dès qu'il se termine.
    // (Le manager prend possession de la mémoire de l'effet!)
    bool pushEffect(CImmEffect* effect, bool loop);

    // Raccourci pour initialisation par projet
    bool pushProject(char const* projectName, bool loop);

    // Raccourci pour initialisation par projet et effet contenu
    bool pushProject(char const* projectName, char const* effectName, bool loop);

signals:

public slots:
    // Rafraîchissement de la pile d'effets
    void tick();

    // Interruption du dernier effet ajouté.
    void popEffect();

    // Interruption et suppression de tous les effets
    void clearAllEffects();

protected:
    void validateEffectStack();

    static bool isProjectPlaying(CImmProject* p);

    bool initializeMouseInternal(void* ptr);

private:
    std::vector<CImmProject*> m_effects;
    static CImmDevice* m_device;
};

#endif // EFFECTMANAGER_H
