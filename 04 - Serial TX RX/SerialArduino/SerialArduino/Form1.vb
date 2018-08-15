

Public Class Form1

    Dim com As IO.Ports.SerialPort
    Dim leitura As String



    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click

        com.Write("LIGA")
        Label1.Text = ""
        OvalShape1.BackColor = Color.Red

    End Sub

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick

        leitura = com.ReadExisting()

        If leitura <> "" Then

            If leitura = "0" + vbCrLf Then
                Label1.Text = "Botão acionado"
                OvalShape1.BackColor = Color.White
            End If
            If leitura = "1" + vbCrLf Then
                Label1.Text = "Botão acionado"
                OvalShape1.BackColor = Color.Red
            End If


        End If


    End Sub

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

        com = My.Computer.Ports.OpenSerialPort("COM3")
        com.BaudRate = 9600
        Label1.Text = ""
        com.Write("DESLIGA")
        OvalShape1.BackColor = Color.White

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click

        com.Write("DESLIGA")
        Label1.Text = ""
        OvalShape1.BackColor = Color.White

    End Sub
End Class
