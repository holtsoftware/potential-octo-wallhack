using Sannel.EcoSystem.Engine;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Media.Imaging;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

namespace Sannel.EcoSystem.UI
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public sealed partial class MainPage : Page
	{
		public MainPage()
		{
			this.InitializeComponent();
		}

		protected override void OnNavigatedTo(NavigationEventArgs e)
		{
			base.OnNavigatedTo(e);
			//if(engine == null)
			//{
				
			//	var gridSize = new GridLength(150);
			//	for(int r=0;r<engine.Rows;r++)
			//	{
			//		Tiles.RowDefinitions.Add(new RowDefinition() { Height = gridSize });
			//	}

			//	for(int c = 0;c<engine.Columns;c++)
			//	{
			//		Tiles.ColumnDefinitions.Add(new ColumnDefinition() { Width = gridSize });
			//	}

			//	refreshGrid();
			//}
		}

		private void refreshGrid()
		{
			//Tiles.Children.Clear();
			//for(int r=0;r<engine.Rows;r++)
			//{
			//	for(int c=0;c<engine.Columns;c++)
			//	{
			//		var ter = engine.GetTerrainAt(r, c);
			//		Image img = new Image();
			//		img.Source = new BitmapImage(ter.ImageFile);
			//		img.SetValue(Grid.RowProperty, r);
			//		img.SetValue(Grid.ColumnProperty, c);
			//		Tiles.Children.Add(img);
			//	}
			//}
		}
	}
}
