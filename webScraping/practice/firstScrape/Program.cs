using HtmlAgilityPack;
using CsvHelper;
using System.Globalization;
using System.Runtime.InteropServices;
using System.Security.Cryptography;





// See https://aka.ms/new-console-template for more information
// var web = new HtmlWeb();

// // loading the target web page 
// var document = web.Load("https://scrapeme.live/shop/");
// var pokemonProducts = new List<PP.PokemonProduct>();

// // selecting all HTML product elements from the current page 
// var productHTMLElements = document.DocumentNode.QuerySelectorAll("li.product");
// // iterating over the list of product elements 
// foreach (var productHTMLElement in productHTMLElements) 
// { 
// 	// scraping the interesting data from the current HTML element 
// 	var url = HtmlEntity.DeEntitize(productHTMLElement.QuerySelector("a").Attributes["href"].Value); 
// 	var image = HtmlEntity.DeEntitize(productHTMLElement.QuerySelector("img").Attributes["src"].Value); 
// 	var name = HtmlEntity.DeEntitize(productHTMLElement.QuerySelector("h2").InnerText); 
// 	var price = HtmlEntity.DeEntitize(productHTMLElement.QuerySelector(".price").InnerText); 
// 	// instancing a new PokemonProduct object 
// 	var pokemonProduct = new PP.PokemonProduct() { Url = url, Image = image, Name = name, Price = price }; 
// 	// adding the object containing the scraped data to the list 
// 	pokemonProducts.Add(pokemonProduct); 
// }

// // initializing the CSV output file 
// using (var writer = new StreamWriter("pokemon-products.csv")) 
// // initializing the CSV writer 
// using (var csv = new CsvWriter(writer, CultureInfo.InvariantCulture)) 
// { 
// 	// populating the CSV file 
// 	csv.WriteRecords(pokemonProducts); 
// }





// var web2 = new HtmlWeb();
// var document2 = web.Load("https://www.pais.co.il/lotto/archive.aspx");
// var numbers = new List<ln.lotteryNumbers>();
// var productHTMLElements2 = document2.DocumentNode.QuerySelectorAll("li.archive_list_item");
// Console.ReadKey(true);



using (var reader = new StreamReader(@"C:\Users\csfwn\git-projects\Projects\webScraping\practice\firstScrape\Lotto.csv"))

using(var csv = new CsvReader(reader, CultureInfo.InvariantCulture)){
    var records = csv.GetRecords<ln.lotteryNumbers>().ToList();
    var table = (from r in records
                        orderby r.strongnum, r.num1, r.num2, r.num3
                        select r).ToList();
    var c = from r in records
            orderby r.strongnum
            group r by r.strongnum into g
            select new {key = g.Key, cnt = g.Count()};        
    var one = records.Where(x => x.num1 == 1 || x.num2 == 1 || x.num3 == 1 || x.num4 == 1 || x.num5 == 1 || x.num6 == 1).Count();
    var two = records.Where(x => x.num1 == 2 || x.num2 == 2 || x.num3 == 2 || x.num4 == 2 || x.num5 == 2 || x.num6 == 2).Count();
    var three = records.Where(x => x.num1 == 3 || x.num2 == 3 || x.num3 == 3 || x.num4 == 3 || x.num5 == 3 || x.num6 == 3).Count();
    var four = records.Where(x => x.num1 == 4 || x.num2 == 4 || x.num3 ==4 || x.num4 == 4 || x.num5 == 4 || x.num6 ==4 ).Count();
    var five = records.Where(x => x.num1 == 5 || x.num2 == 5 || x.num3 == 5 || x.num4 == 5 || x.num5 == 5 || x.num6 ==5).Count();
    var six = records.Where(x => x.num1 == 6 || x.num2 == 6 || x.num3 == 6 || x.num4 == 6 || x.num5 == 6 || x.num6 == 6).Count();
    var seven= records.Where(x => x.num1 == 7 || x.num2 == 7 || x.num3 ==  7|| x.num4 == 7 || x.num5 == 7 || x.num6 == 7).Count();

    var table1 = table.ToList();
        foreach(var x in table){
        Console.WriteLine(x.ToString());
    }
    IEnumerable<string> ie = from r in records orderby r.num2 select r.ToString();
    File.WriteAllLines("data.xml", ie);
    foreach(var x in c){
        Console.WriteLine(x.key.ToString() + ':' + x.cnt.ToString());
    }
}
