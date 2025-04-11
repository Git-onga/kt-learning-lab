Public Class Form1
    Dim fvalue As Double

    Private Sub BtnClac_Click(sender As Object, e As EventArgs) Handles BtnClac.Click
        ' Declare variables
        Dim pvalue As Double
        Dim r As Double
        Dim n As Double

        ' Parse input values
        If Not Double.TryParse(TxtBoxValue.Text, pvalue) Then
            MessageBox.Show("Please enter a valid Present Value.")
            Exit Sub
        End If

        If Not Double.TryParse(TxtBoxRates.Text, r) Then
            MessageBox.Show("Please enter a valid Rate of Depreciation.")
            Exit Sub
        End If

        If Not Double.TryParse(TxtBoxYrs.Text, n) Then
            MessageBox.Show("Please enter a valid Number of Years.")
            Exit Sub
        End If

        ' Calculate future value using the reducing balance formula
        fvalue = pvalue * (1 - r / 100) ^ n

        ' Display result in a MessageBox
        MessageBox.Show("The Future Value is: " & fvalue.ToString("F2"))
    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load

    End Sub
End Class
