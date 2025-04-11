Public Class Form1
    Public Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Dim dblNum1 As Double = Double.TryParse(TextBox1.Text, dblNum1)
        Dim dblNum2 As Double = Double.TryParse(TextBox2.Text, dblNum2)
        Dim sum As Double = dblNum1 + dblNum2

        Label5.Text = sum

    End Sub
    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Dim dblNum1 As Double = Double.TryParse(TextBox1.Text, dblNum1)
        Dim dblNum2 As Double = Double.TryParse(TextBox2.Text, dblNum2)
        Dim subtract As Double = dblNum1 - dblNum2

        Label5.Text = subtract
    End Sub
    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        Dim dblNum1 As Double = Double.TryParse(TextBox1.Text, dblNum1)
        Dim dblNum2 As Double = Double.TryParse(TextBox2.Text, dblNum2)
        Dim multiply As Double = dblNum1 * dblNum2

        Label5.Text = multiply

    End Sub
    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        Dim dblNum1 As Double = Double.TryParse(TextBox1.Text, dblNum1)
        Dim dblNum2 As Double = Double.TryParse(TextBox2.Text, dblNum2)
        Dim divide As Double = dblNum1 / dblNum2

        Label5.Text = divide

    End Sub
    Private Sub Button5_Click(sender As Object, e As EventArgs) Handles Button5.Click
        Dim dblNum1 As Double = Double.TryParse(TextBox1.Text, dblNum1)
        Dim dblNum2 As Double = Val(TextBox2.Text)
        Dim modulus As Double = dblNum1 Mod dblNum2

        Label5.Text = modulus

    End Sub
    Private Sub Button6_Click(sender As Object, e As EventArgs) Handles Button6.Click
        Dim dblNum1 As Double = Double.TryParse(TextBox1.Text, dblNum1)
        Dim dblNum2 As Double = Double.TryParse(TextBox2.Text, dblNum2)
        Dim power As Double = dblNum1 ^ dblNum2

        Label5.Text = power

    End Sub
    Private Sub Button7_Click(sender As Object, e As EventArgs) Handles Button7.Click
        TextBox1.Clear()
        TextBox2.Clear()
        Label5.Text = "Results"

        TextBox1.Focus()
    End Sub

    Private Sub Button8_Click(sender As Object, e As EventArgs) Handles Button8.Click
        Me.Close()
    End Sub


End Class
