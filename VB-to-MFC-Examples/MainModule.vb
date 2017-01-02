Imports System
Imports System.Threading
Imports MFCExampleSnippets

Module MainModule

    Sub Main()
        Dim oApp As IMFCExampleSnippets
        oApp = CreateObject("MFCExampleSnippets.Application")
        If oApp IsNot Nothing Then

            Console.WriteLine("Okay.  Created MFC-Example-Snippets application.")

        End If
        Console.Write("Please press <Enter> to finish...")
        Console.ReadKey()
    End Sub

End Module
