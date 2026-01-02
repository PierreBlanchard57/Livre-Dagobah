#include "effectmanager.h"

// IFC
#ifdef UNICODE
#undef UNICODE
#include <IFC.h>
#endif

bool EffectManager::isProjectPlaying(CImmProject *p)
{
    int nCompounds = p->GetNumEffects();
    if (!nCompounds)
        return false;
    for (int c = 0; c < nCompounds; ++c) {
        CImmCompoundEffect* ce = p->GetEffect(c);
        for (int e = 0; e < ce->GetNumberOfContainedEffects(); ++e)
            if (ce->GetContainedEffect(e)->GetIsPlaying())
                return true;
    }
    return false;
}

EffectManager::EffectManager(QObject *parent) : QObject(parent)
{
    m_device = nullptr;
}

bool EffectManager::initializeMouse(const QWindow &window)
{
    if (m_device)
        return true;

    HWND handle = reinterpret_cast<HWND>(window.winId());

    CImmMouse* dev = new CImmMouse;
    if (dev->Initialize(GetModuleHandle(NULL), handle)) {
        m_device = dev;
        return true;
    }
    return false;
}

void EffectManager::validateEffectStack()
{
    CImmProject* temp;
    for (auto itr = m_effects.begin(); itr != m_effects.end(); ++itr) {
        temp = *itr;
        if (!isProjectPlaying(temp)) {
            delete temp;
            itr = m_effects.erase(itr);
        }
    }
}

bool EffectManager::pushEffect(CImmEffect *effect, bool loop)
{
    // Suppression de tous les effets périmés avant de continuer
    validateEffectStack();

    CImmProject* project = new CImmProject;
    project->AddEffect("root", effect);
    bool ok = project->Start(0, loop? INFINITY : 1, 0);
    if (ok)
        m_effects.push_back(project);
    return ok;
}

bool EffectManager::pushProject(const char *projectName, bool loop)
{
    CImmProject* project = new CImmProject;
    if (project->OpenFile(projectName, m_device)) {
        if (project->Start(0, loop, 0, m_device)) {
            m_effects.push_back(project);
            return true;
        }
    }
    return false;
}

void EffectManager::tick()
{

}

void EffectManager::popEffect()
{
    if (m_effects.size()) {
        CImmProject* pro = m_effects[m_effects.size()-1];
        if (isProjectPlaying(pro))
            pro->Stop();
        delete pro;
        m_effects.pop_back();
    }
}

void EffectManager::clearAllEffects()
{
    for (auto* pro : m_effects) {
        if (isProjectPlaying(pro))
            pro->Stop();
        delete pro;
    }
    m_effects.clear();
}
