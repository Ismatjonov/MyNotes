# 📝 My notes about learning process
All notes about learning process and programming new tips 🫯

---

# 🕹️ Skills:
- .NET Frameworks
- MSSQL Server
- Version Control (Git)
- Vibe Coding)

---

# 👤 About me:

```JavaScript
bakhtovar = {
    name: "Bakhtovar",
    surname: "Ismatjonov",
    age: 19,
    gender: "male",
    isMarried: false 
};
```

---

# Notes:

## 1. Connect to Database:

```csharp
using System.Data.SqlClient;

class Program
{
    static void Main(string[] args)
    {
        string stringConnection = 
        "SERVER=.\\SQLEXPRESS;Database=test_db;Trusted_Connection=True;TrustServerCertificate=True";
        
        // Connecting
        SqlConnection connect = new SqlConnection(connectionString);
        
        // Checking for connection is true...
        try
        {
            Console.WriteLine("Checking...");
            connection.Open();
            Console.WriteLine("Connected!");
        }
        catch(Exception ex)
        {
            Console.WriteLine("Error: " + ex.Message);
        }
        finally
        {
            Console.ReadLine();
        }
    }
}
```
## 2. Multithreading
Creating and start a new thread
```csharp
Thread myThread = new Thread(Print);
myThread.Start();

void Print()
{
    Console.WriteLine("Hello Threads");
}

public delegate void ThreadStart();
```
Some useful properties and methods of Thread's class
```csharp
Thread.Name;  // Name of current thread
Thread.Sleep();  // Set up the timer for executing
```
Using method Sleep()
```csharp
using System.Threading;
 
for(int i = 0; i < 10; i++)
{
    Thread.Sleep(500);      // задержка выполнения на 500 миллисекунд
    Console.WriteLine(i);
}
```
Thread's synchronization with operator `lock`
```csharp
int x = 0;  // некоторый общий ресурс
Lock _lockObj = new(); // объект-заглушка для синхронизации доступа
// запускаем пять потоков
for (int i = 1; i < 6; i++)
{
    Thread myThread = new(Print);
    myThread.Name = $"Поток {i}";
    myThread.Start();
}
 
void Print()
{
    lock(_lockObj)  // начало критической секции
    {
        x = 1;
        for (int i = 1; i < 5; i++)
        {
            Console.WriteLine($"{Thread.CurrentThread.Name}: {x}");
            x++;
            Thread.Sleep(100);
        }
    }  // завершение критической секции
}
```
Operator `lock` with methods:
```csharp
int x = 0;  // некоторый общий ресурс
Lock _lockObj = new(); // объект-заглушка для синхронизации доступа
// запускаем пять потоков
for (int i = 1; i < 6; i++)
{
    Thread myThread = new(Print);
    myThread.Name = $"Поток {i}";
    myThread.Start();
}
 
void Print()
{
    _lockObj.Enter();  // начало критической секции
    try
    {
        x = 1;
        for (int i = 1; i < 5; i++)
        {
            Console.WriteLine($"{Thread.CurrentThread.Name}: {x}");
            x++;
            Thread.Sleep(100);
        }
    }
    finally 
    {
        _lockObj.Exit();  // завершение критической секции
    }
}
```
method `TryEnter()`
```csharp
int x = 0;  // некоторый общий ресурс
Lock _lockObj = new(); // объект-заглушка для синхронизации доступа
// запускаем пять потоков
for (int i = 1; i < 6; i++)
{
    Thread myThread = new(Print);
    myThread.Name = $"Поток {i}";
    myThread.Start();
}
 
 
void Print()
{
    if (_lockObj.TryEnter())  // начало критической секции
    {
        try
        {
            x = 1;
            for (int i = 1; i < 6; i++)
            {
                Console.WriteLine($"{Thread.CurrentThread.Name}: {x}");
                x++;
                Thread.Sleep(100);
            }
        }  
        finally { _lockObj.Exit(); } // завершение критической секции
    }
}
```
method `EnterScope()`. 
A very simple way to synchronize threads
```csharp
int x = 0;  // некоторый общий ресурс
Lock _lockObj = new(); // объект-заглушка для синхронизации доступа
// запускаем пять потоков
for (int i = 1; i < 6; i++)
{
    Thread myThread = new(Print);
    myThread.Name = $"Поток {i}";
    myThread.Start();
}
 
 
void Print()
{
    using (_lockObj.EnterScope())  // начало критической секции
    {
        x = 1;
        for (int i = 1; i < 6; i++)
        {
            Console.WriteLine($"{Thread.CurrentThread.Name}: {x}");
            x++;
            Thread.Sleep(100);
        }
    }  // завершение критической секции
}
```
## Task
Creating a new task
```csharp
Task task1 = new Task(() => Console.WriteLine("Task1 is executed"));
task1.Start();
 
Task task2 = Task.Factory.StartNew(() => Console.WriteLine("Task2 is executed"));
 
Task task3 = Task.Run(() => Console.WriteLine("Task3 is executed"));
```
Running Tasks
```csharp
Task task1 = new Task(() => Console.WriteLine("Task1 is executed"));
task1.Start();
 
Task task2 = Task.Factory.StartNew(() => Console.WriteLine("Task2 is executed"));
 
Task task3 = Task.Run(() => Console.WriteLine("Task3 is executed"));
 
task1.Wait();   // ожидаем завершения задачи task1
task2.Wait();   // ожидаем завершения задачи task2
task3.Wait();   // ожидаем завершения задачи task3
```
Exploring method Wait()
```csharp
Console.WriteLine("Main Starts");
// создаем задачу
Task task1 = new Task(() =>
{
    Console.WriteLine("Task Starts");
    Thread.Sleep(1000);     // задержка на 1 секунду - имитация долгой работы
    Console.WriteLine("Task Ends");
 });
task1.Start();  // запускаем задачу
Console.WriteLine("Main Ends");
task1.Wait();   // ожидаем выполнения задачи
```
Running synchronously
```csharp
Console.WriteLine("Main Starts");
// создаем задачу
Task task1 = new Task(() =>
{
    Console.WriteLine("Task Starts");
    Thread.Sleep(1000); 
    Console.WriteLine("Task Ends");
 });
task1.RunSynchronously(); // запускаем задачу синхронно
Console.WriteLine("Main Ends"); // этот вызов ждет завершения задачи task1 
```
Properties of class Task
```csharp
Task task1 = new Task(() =>
{
    Console.WriteLine($"Task{Task.CurrentId} Starts");
    Thread.Sleep(1000);
    Console.WriteLine($"Task{Task.CurrentId} Ends");
 });
task1.Start(); //запускаем задачу
 
// получаем информацию о задаче
Console.WriteLine($"task1 Id: {task1.Id}");
Console.WriteLine($"task1 is Completed: {task1.IsCompleted}");
Console.WriteLine($"task1 Status: {task1.Status}");
 
task1.Wait(); // ожидаем завершения задачи
```