using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            GenerateWord util = new GenerateWord();
            int sizeList = -1, i, sizeWord = -1;
            List<string> palavras = new List<string>();

            while (sizeList < 0) // validando as entradas para o tamanho do vetor retornado
            {
                Console.WriteLine("Informe o tamanho do vetor de strings: ");
                sizeList = Convert.ToInt32(Console.ReadLine());
                if (sizeList < 0)
                {
                    Console.WriteLine("O tamanho precisa ser maior que zero.");
                }
                if (sizeList == 0) // caso o usuário digite 0 o programa entenderá como 1 e criará uma única palavra
                {
                    sizeList = 1;
                }
            }
            while (sizeWord < 0) // validando as entradas para o tamanho das palavras no vetor
            {
                Console.WriteLine("Informe o tamanho das palavras no vetor: ");
                sizeWord = Convert.ToInt32(Console.ReadLine());
                if (sizeWord < 0)
                {
                    Console.WriteLine("O tamanho precisa ser maior que zero.");
                }
                if (sizeWord == 0)
                {
                    sizeWord = 1; // caso o usuário digite 0 o programa entenderá como 1 e irá gerar 1 caracter aleatório
                }

            }
            Random random = new Random();

            for (i = 0; i < sizeList; i++)
            {
                palavras.Add(util.Generate(sizeWord, random)); // gerando caracteres e adicionando no vetor
            }
            int choice; // variável de controle do switch (menu)

            Console.WriteLine("Escolha a notação da saída das palavras:");
            Console.WriteLine("0 - quebra de linha");
            Console.WriteLine("1 - não quebrar linha");
            Console.WriteLine("2 - notação de sql para 1 coluna de string ex. ('abcd')");

            choice = Convert.ToInt32(Console.ReadLine());
            // Listagens com as notações escolhida.
            // em todas as listagens há controle de vírgulas, ou seja, no último elemento não é adicionado vírgula.
            switch (choice)
            {
                case 0: // notação sem quebra de linha
                    for (i = 0; i < sizeList; i++)
                    {
                        if (i == sizeList - 1)
                        {
                            Console.Write("'" + palavras[i] + "'"); 
                            break;
                        }
                        Console.WriteLine("'" + palavras[i] + "',");
                    }
                    break;
                case 1: // notação com quebra de linha
                    for (i = 0; i < sizeList; i++)
                    {
                        if (i == sizeList - 1)
                        {
                            Console.Write("'" + palavras[i] + "'");
                            break;
                        }
                        Console.Write("'" + palavras[i] + "',");
                    }
                    break;
                case 2: // notação sql sem quebra de linha
                    for (i = 0; i < sizeList; i++)
                    {
                        if (i == sizeList - 1)
                        {
                            Console.Write("('" + palavras[i] + "')");
                            break;
                        }
                        Console.WriteLine("('" + palavras[i] + "'),");
                    }
                    break;
                default:
                    Console.WriteLine("Opção Errada!");
                    break;
            }
            Console.WriteLine("  ");
            Console.WriteLine("Fim do programa. Pressione Qualquer tecla para sair.");
            Console.ReadKey();
        }           
    }
}

