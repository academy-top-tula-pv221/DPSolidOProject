#include <iostream>
#include <vector>

using namespace std;

// паттерн Стратегия
/*
class IMeal
{
public:
    virtual void Make() = 0;
};
class PotatoMeal : public IMeal
{
    void Make() override
    {
        cout << "Чистим картошку\n";
        cout << "Ставим картошку на огонь\n";
        cout << "Добавляем специи\n";
        cout << "Сливаем воду\n";
        cout << "Толчем картошку\n";
        cout << "Картофельное пюре готово\n";
    }
};
class SalatMeal : public IMeal
{
    void Make() override
    {
        cout << "нарезаем помидоры\n";
        cout << "нарезаем огурцы\n";
        cout << "нарезаем зелень\n";
        cout << "заправляем сметаной\n";
        cout << "добавляем специиб перемешиваем\n";
        cout << "Салат готов\n";
    }
};
class Cook
{
    string name;
public:
    string& Name() { return name; }
    Cook(string name) : name{ name } {}

    void MakeDinner(IMeal* meal)
    {
        meal->Make();
    }
};
*/

// паттерн Шаблонный метод
class MealBase
{
public:
    void Make()
    {
        Prepare();
        MealCook();
        FinalSteps();
    }
    virtual void Prepare() = 0;
    virtual void MealCook() = 0;
    virtual void FinalSteps() = 0;
};

class PotateMeal : public MealBase
{
    void Prepare() override
    {
        cout << "Чистим картошку\n";
        cout << "Ставим картошку на огонь\n";
    }
    void MealCook() override
    {
        cout << "Добавляем специи\n";
        cout << "Сливаем воду\n";
        cout << "Толчем картошку\n";
    }

    void FinalSteps() override
    {
        cout << "Посыпаем зеленью\n";
        cout << "Картофельное пюре готово\n";
    }
};

class SalatMeal : public MealBase
{
    void Prepare() override
    {
        cout << "нарезаем помидоры\n";
        cout << "нарезаем огурцы\n";
        cout << "нарезаем зелень\n";
        
        cout << "Салат готов\n";
    }
    void MealCook() override
    {
        cout << "заправляем сметаной\n";
        cout << "добавляем специи, перемешиваем\n";
    }

    void FinalSteps() override
    {
        cout << "Салат готов\n";
    }
};

class Cook
{
    string name;
public:
    string& Name() { return name; }
    Cook(string name) : name{ name } {}

    void MakeDinner(vector<MealBase*> menu)
    {
        for (MealBase* meal : menu)
            meal->Make();
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Cook cook("Bob");
    /*
    cook.MakeDinner(new PotatoMeal());
    cout << "\n";
    cook.MakeDinner(new SalatMeal());
    */

    vector<MealBase*> menu;
    menu.push_back(new PotateMeal());
    menu.push_back(new SalatMeal());
    cook.MakeDinner(menu);
}
