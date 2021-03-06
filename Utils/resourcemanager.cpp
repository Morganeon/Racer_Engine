#include "Utils\resourcemanager.h"

ResourceManager::ResourceManager()
{

}
ResourceManager::~ResourceManager()
{

}

int ResourceManager::storeMesh(QString name, Mesh *meshPointer)
{
    meshBatch.push_back(meshPointer);
    meshMap[name] = meshBatch.size() - 1;
    return meshBatch.size();
}

int ResourceManager::storeShape(QString name, btCollisionShape *shapePointer)
{
    shapeBatch.push_back(shapePointer);
    shapeMap[name] = shapeBatch.size() - 1;
    return shapeBatch.size();
}

Mesh *ResourceManager::retrieveMesh(int i)
{
    if (i>=meshBatch.size()) return 0;
    return meshBatch.at(i);
}

btCollisionShape *ResourceManager::retrieveShape(int i)
{
    if (i>=shapeBatch.size()) return 0;
    return shapeBatch.at(i);
}


Mesh *ResourceManager::retrieveMesh(QString name)
{

    int i = -1;
    try
    {
        i= meshMap.at(name);
    }
    catch (std::exception e)
    {
        qDebug() << "Unable to retrieve mesh ("<<name<<"): " << e.what();
    }
    if (i==-1) return 0;

    return meshBatch.at(i);
}

btCollisionShape *ResourceManager::retrieveShape(QString name)
{
    int i = -1;
    try
    {
        i= shapeMap.at(name);
    }
    catch (std::exception e)
    {
        qDebug() << "Unable to retrieve shape ("<<name<<"): " << e.what();
    }
    if (i==-1) return 0;
    return shapeBatch.at(i);
}

