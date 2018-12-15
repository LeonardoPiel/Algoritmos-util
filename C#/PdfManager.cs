//using EdileneteSystem.DatabaseConnection;
using MigraDoc.DocumentObjectModel;
using MigraDoc.DocumentObjectModel.Tables;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
// CLASSE PARA FORMAS E PDF'S
// ESSA CLASSE PRECISA DE ALGUMAS MUDANÇAS PARA SE TORNAR MAIS GENÉRICA. MAS JÁ ESTÁ BEM INTERESSANTE PARA TRABALHOS!
//TO DO:
//ADICIONAR EXTENSÃO MIGRADOC PDF SHARP NO NUGET MANAGER
namespace [namespace]
{
    public class PdfManager
    {
        public static Document CreateDocument(string Propriedade, string Nome = "", string InscricaoEstadual = "")
        {
            Section section;
            Document doc;
            doc = new Document();
            section = doc.AddSection();
            section.PageSetup.OddAndEvenPagesHeaderFooter = true;

            section.AddParagraph("RELATÓRIO - "+Convert.ToString(DateTime.Now.Date)).Format.Alignment = ParagraphAlignment.Center;

            section.AddParagraph("Proprietário: " + Nome);
            section.AddParagraph("Inscrição Estadual: " + InscricaoEstadual);
            section.AddParagraph("Propriedade: " + Propriedade);
            section.AddParagraph();

            Paragraph paragraph = new Paragraph();
            paragraph.AddText("Página ");
            paragraph.AddPageField();
            paragraph.AddText(" de ");
            paragraph.AddNumPagesField();

            section.Footers.Primary.Add(paragraph);
            section.Footers.EvenPage.Add(paragraph.Clone());

            section.PageSetup.Orientation = Orientation.Landscape;

            DefineStyles(doc);

            return doc;
        }
        static void DefineStyles(Document doc)
        {

            // Encontra o estilo pré definido: Normal
            Style style = doc.Styles["Normal"];
           
            style.Font.Name = "Arial";
            // setando algumas configurações: header, alinhamento de tabela e etc.

            style = doc.Styles[StyleNames.Header];
            style.ParagraphFormat.AddTabStop("16cm", TabAlignment.Right);

            style = doc.Styles[StyleNames.Footer];
            style.ParagraphFormat.AddTabStop("8cm", TabAlignment.Center);

            // Criando tabela baseada no estilo normal
            style = doc.Styles.AddStyle("Table", "Normal");
            style.Font.Name = "Verdana";
            style.Font.Name = "Times New Roman";
            style.Font.Size = 9;
        }
        public static void SaveAll(Document doc, string path)
        {
            try
            {
                MigraDoc.Rendering.PdfDocumentRenderer docRend = new MigraDoc.Rendering.PdfDocumentRenderer(false);

                docRend.Document = doc;


                docRend.RenderDocument();

                string someName = GenerateWord.Generate(4);

                string FileName = "rel" + someName + ".pdf";

                docRend.PdfDocument.Save(path+"\\"+FileName);

                System.Diagnostics.ProcessStartInfo procInfo = new System.Diagnostics.ProcessStartInfo();

                procInfo.FileName = path + "\\" + FileName;

                System.Diagnostics.Process.Start(procInfo);
            }
            catch (Exception ex)
            {
                System.Windows.Forms.MessageBox.Show("Ocorreu algo errado", "Aviso", System.Windows.Forms.MessageBoxButtons.OK, System.Windows.Forms.MessageBoxIcon.Information);
                throw ex;
            }
        }

        public class Tables
        {
            public Table CreateTable(double borderWidth, int ParagrafType)
            {
                var borderW = borderWidth == 0 ? borderWidth = 0.5 : borderWidth;

                Table table = new Table();
                table.Style = "Table";

                table.Borders.Left.Visible = false;
                table.Borders.Right.Visible = false;

                table.Borders.Width = borderW;
                switch (ParagrafType)
                {
                    case 1:
                        table.Format.Alignment = ParagraphAlignment.Center;
                        break;
                    case 2:
                        table.Format.Alignment = ParagraphAlignment.Right;
                        break;
                    case 3:
                        table.Format.Alignment = ParagraphAlignment.Justify;
                        break;
                    default:
                        table.Format.Alignment = ParagraphAlignment.Left;
                        break;
                }
                return table;
            }
            public class HeaderProperties
            {
                public string Column { get; set; }
                public double SizeColumn { get; set; }
            }
            public Row CreateHeader(Table table, string Produto, List<HeaderProperties> ColumnNames)
            {
                Column column;
                Row rowProduct;
                Row rowHeader;
                Cell cell;
                Cell cellItens;

                //CONFIGURANDO AS COLUNAS
                int counter = 0;
                try
                {
                    foreach (var item in ColumnNames)
                    {
                        column = table.AddColumn(Unit.FromCentimeter(item.SizeColumn));
                        column.Format.Alignment = ParagraphAlignment.Left;

                        counter++;
                    }
                }
                catch (Exception e)
                {
                    throw e;
                }

                try
                {
                    //CONFIGURANDO A LINHA QUE VAI CONTER O NOME DO PRODUTO
                    rowProduct = table.AddRow();
                    rowProduct.HeadingFormat = true;
                    rowProduct.Cells[0].MergeRight = counter - 1; //DANDO MERGE PARA APARECER APENAS O NOME DO PRODUTO 

                    cell = rowProduct.Cells[0];
                    cell.AddParagraph(Produto);
                    cell.Format.Font.Size = Unit.FromCentimeter(0.4);
                    cell.Format.Font.Bold = true;

                    //CRIANDO A LINHA DE CABEÇALHO
                    rowHeader = table.AddRow();
                    rowHeader.Format.Alignment = ParagraphAlignment.Left;
                    int count = 0;

                    //CRIANDO E CONFIGURANDO AS CÉLULAS DO CABEÇALHO
                    foreach (var item in ColumnNames)
                    {
                        cellItens = rowHeader.Cells[count];
                        cellItens.AddParagraph(Convert.ToString(item.Column));
                        cellItens.Format.Font.Bold = true;

                        count++;
                    }
                    return rowHeader;
                }
                catch (Exception e)
                {
                    throw e;
                }
            }
            public void CreateFooter(Table table, string TotalValor, string TotalPeso)
            {
                Row row;
                Cell cell;
                row = table.AddRow();
                row.Format.Font.Bold = true;

                cell = row.Cells[3];
                cell.AddParagraph("Total Peso (Kg):");
                cell.AddParagraph(TotalPeso);


                cell = row.Cells[4];
                cell.AddParagraph("Total Valor R$:");
                cell.AddParagraph(TotalValor);
            }

            public void PopulateTable<T>(Table table, Row HeaderRow, List<T> items, Document doc)
            {
                doc.LastSection.Add(table);

                Cell cell;
                int c = 0;
                IList<object> Values = new List<object>();

                Type myType = items[0].GetType();

                IList<PropertyInfo> props = new List<PropertyInfo>(myType.GetProperties());

                int counterInside;
                int counterOutside;

                for (counterOutside = 0; counterOutside < items.Count; counterOutside++)
                {
                    HeaderRow = table.AddRow();
                    c = 0;
                    for (counterInside = 0; counterInside < props.Count(); counterInside++)
                    {
                        cell = HeaderRow.Cells[c];
                        cell.AddParagraph(Convert.ToString(props[c].GetValue(items[counterOutside], null)));

                        c++;
                    }
                }
            }
        }



    }
}
