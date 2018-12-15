using EdileneteSystem.DatabaseConnection;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace [PUT YOUR NAME SPACE].[HERE]
{
    public class FormManager
    {
       // Os itens do formulário devem estar organizados em groupBox.
        public static void HabilitaCampos(bool act, Form form) // parâmetros: dependendo do valor da variável 'act' o método habilita
                                                               // ou desabilita os campos de um formulário 'form'
        {
            List<GroupBox> groupBox = new List<GroupBox>();
            groupBox = GetGroupBox(form);

            if (act)
            {
                foreach (var item in groupBox)
                {
                    foreach (var obj in item.Controls.OfType<TextBox>())
                    {
                        obj.Enabled = true;
                    }
                    foreach (var obj in item.Controls.OfType<DateTimePicker>())
                    {
                        obj.Enabled = true;
                    }
                    foreach (var obj in item.Controls.OfType<MaskedTextBox>())
                    {
                        obj.Enabled = true;
                    }
                    foreach (var obj in item.Controls.OfType<ComboBox>())
                    {
                        obj.Enabled = true;
                    }
                    foreach (var obj in item.Controls.OfType<GroupBox>())
                    {
                        obj.Enabled = true;
                    }
                }

            }
            else
            {
                foreach (var item in groupBox)
                {
                    foreach (var obj in item.Controls.OfType<TextBox>())
                    {
                        obj.Enabled = false;
                        obj.Text = "";
                    }
                    foreach (var obj in item.Controls.OfType<DateTimePicker>())
                    {
                        obj.Enabled = false;
                    }
                    foreach (var obj in item.Controls.OfType<MaskedTextBox>())
                    {
                        obj.Enabled = false;
                        obj.Text = "";
                    }
                    foreach (var obj in item.Controls.OfType<ComboBox>())
                    {
                        obj.Enabled = false;
                    }
                    foreach (var obj in item.Controls.OfType<GroupBox>())
                    {
                        obj.Enabled = false;
                    }
                }
            }
        }
        
        public static List<GroupBox> GetGroupBox(Form form) // encontra os possíveis groupBox que estejam no formulário: form
        {

            List<GroupBox> listGrp = new List<GroupBox>();
            foreach (var item in form.Controls.OfType<GroupBox>())
            {
                listGrp.Add(item);
            }

            return listGrp; // retorna uma lista de groupBox;
        }

        public static void RemovePrincipalForms(Panel panel) // fecha e abre Panels. Simplificação para abertura e fechamento.
        {
            foreach (var item in panel.Controls.OfType<Form>())
            {
                panel.Controls.Remove(item);
            }
        }

        public static void LoadCities(ComboBox comboBox) // carrega as cidades do banco de dados
        {
            using (SysEdineteEntities db = new SysEdineteEntities())
            {
                try
                {
                    foreach (var item in db.Cidades.Where(q => q.EstadoId == 12).Select(q => q.Nome).ToList())
                    {
                        comboBox.Items.Add(item);
                    }
                    comboBox.Items.Add("Selecione...");
                    comboBox.SelectedIndex = comboBox.FindStringExact("Selecione...");
                }
                catch (Exception ex)
                {
                    throw ex;
                }
            }
        }
        public static void ClearMask(Form form) // remove as mascaras de todos os campos do tipo MaskedTextBox
        {
            List<GroupBox> groupBox = new List<GroupBox>();
            groupBox = GetGroupBox(form);
            foreach (var i in groupBox)
            {
                foreach (var obj in i.Controls.OfType<MaskedTextBox>())
                {
                    obj.TextMaskFormat = MaskFormat.ExcludePromptAndLiterals;
                }

                foreach (var obj in i.Controls.OfType<TextBox>())
                {
                    obj.Text.Replace(" ", string.Empty);// removendo espaços
                }
            }

        }
        //Identifica qual radio button está habilitado e ativar itens dos formulários correspondentes de forma dinâmica
        public static void SwitchRbt(RadioButton rbtHabilitado, Panel panelHabilitado, GroupBox grpParent)
        {
            // verificando se o objeto não é nulo
            if (!(rbtHabilitado != null))
            {
                return;
            }
            //SEÇÃO HABILITADO
            panelHabilitado.Visible = true;
            foreach (var obj in panelHabilitado.Controls.OfType<MaskedTextBox>())
            {
                obj.Focus();
                obj.Visible = true;
            }

            foreach (var obj in panelHabilitado.Controls.OfType<TextBox>())
            {
                obj.Focus();
                obj.Visible = true;
            }

            foreach (var obj in panelHabilitado.Controls.OfType<Label>())
            {
                obj.Visible = true;
            }


            //SEÇÃO DESABILITADO

            foreach (var item in grpParent.Controls.OfType<Panel>())
            {
                if (item.Name != panelHabilitado.Name)
                {
                    item.Visible = false;
                    if (item.Controls.OfType<RadioButton>().Count() > 0)
                    {
                        item.Visible = true;
                    }
                    foreach (var obj in item.Controls.OfType<TextBox>())
                    {
                        obj.Visible = false;
                    }
                    foreach (var obj in item.Controls.OfType<MaskedTextBox>())
                    {
                        obj.Visible = false;
                    }
                    foreach (var obj in item.Controls.OfType<Label>())
                    {
                        obj.Visible = false;
                    }
                }
            }
        }

        public static void RestoreMask(Form form) // restaura as máscaras dos objetos do tipo maskedTextBox
        {
            List<GroupBox> groupBox = new List<GroupBox>();
            groupBox = GetGroupBox(form);
            foreach (var i in groupBox)
            {
                foreach (var obj in i.Controls.OfType<MaskedTextBox>())
                {
                    obj.TextMaskFormat = MaskFormat.IncludePromptAndLiterals;
                }
            }

        }

    }
}
