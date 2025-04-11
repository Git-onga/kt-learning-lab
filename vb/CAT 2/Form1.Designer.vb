<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()>
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.TxtBoxValue = New System.Windows.Forms.TextBox()
        Me.TxtBoxRates = New System.Windows.Forms.TextBox()
        Me.TxtBoxYrs = New System.Windows.Forms.TextBox()
        Me.BtnClac = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 13.0!)
        Me.Label1.Location = New System.Drawing.Point(20, 29)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(151, 28)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "Present Value"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.Label2.Font = New System.Drawing.Font("Microsoft Sans Serif", 13.0!)
        Me.Label2.Location = New System.Drawing.Point(20, 93)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(265, 28)
        Me.Label2.TabIndex = 1
        Me.Label2.Text = "Interest Rates Per Annum"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.Label3.Font = New System.Drawing.Font("Microsoft Sans Serif", 13.0!)
        Me.Label3.Location = New System.Drawing.Point(20, 172)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(180, 28)
        Me.Label3.TabIndex = 2
        Me.Label3.Text = "Number of Years"
        '
        'TxtBoxValue
        '
        Me.TxtBoxValue.Location = New System.Drawing.Point(417, 29)
        Me.TxtBoxValue.Name = "TxtBoxValue"
        Me.TxtBoxValue.Size = New System.Drawing.Size(236, 22)
        Me.TxtBoxValue.TabIndex = 3
        Me.TxtBoxValue.Text = "0"
        '
        'TxtBoxRates
        '
        Me.TxtBoxRates.Location = New System.Drawing.Point(417, 93)
        Me.TxtBoxRates.Name = "TxtBoxRates"
        Me.TxtBoxRates.Size = New System.Drawing.Size(236, 22)
        Me.TxtBoxRates.TabIndex = 4
        Me.TxtBoxRates.Text = "0"
        '
        'TxtBoxYrs
        '
        Me.TxtBoxYrs.Location = New System.Drawing.Point(417, 172)
        Me.TxtBoxYrs.Name = "TxtBoxYrs"
        Me.TxtBoxYrs.Size = New System.Drawing.Size(236, 22)
        Me.TxtBoxYrs.TabIndex = 5
        Me.TxtBoxYrs.Text = "0"
        '
        'BtnClac
        '
        Me.BtnClac.Font = New System.Drawing.Font("Microsoft Sans Serif", 13.0!)
        Me.BtnClac.Location = New System.Drawing.Point(219, 254)
        Me.BtnClac.Name = "BtnClac"
        Me.BtnClac.Size = New System.Drawing.Size(263, 58)
        Me.BtnClac.TabIndex = 6
        Me.BtnClac.Text = "Calculate Future Value"
        Me.BtnClac.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(8.0!, 16.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(800, 450)
        Me.Controls.Add(Me.BtnClac)
        Me.Controls.Add(Me.TxtBoxYrs)
        Me.Controls.Add(Me.TxtBoxRates)
        Me.Controls.Add(Me.TxtBoxValue)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Name = "Form1"
        Me.Text = "Future Value Calculator"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents Label1 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents TxtBoxValue As TextBox
    Friend WithEvents TxtBoxRates As TextBox
    Friend WithEvents TxtBoxYrs As TextBox
    Friend WithEvents BtnClac As Button
End Class
