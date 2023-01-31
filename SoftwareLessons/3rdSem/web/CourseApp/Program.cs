using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.FileProviders;

var builder = WebApplication.CreateBuilder(args);
builder.Services.AddRazorPages();
builder.Services.AddControllers();
var app = builder.Build();

//app.MapGet("/", () => "Hello World!");

//localhost:5000/course/list
//localhost:5000/course/details

app.UseRouting();

app.MapControllerRoute(
    "CoursesByReleased",
    "courses/released/{year?}/{month?}",
    new {Controller="Course", Action="ByReleased"},
    new {year=@"\d{4}", month=@"\d{2}"}
);


app.UseEndpoints(endpoints=>
{
    endpoints.MapControllerRoute(
        name: "default",
        pattern: "{controller=home}/{action=index}/{id?}"
    );
});




app.UseStaticFiles();   //wwwroot 


app.UseStaticFiles(new StaticFileOptions
{
    // Requires the following import:
    // using System.IO;
    // using Microsoft.Extensions.FileProviders;
    FileProvider = new PhysicalFileProvider(
            Path.Combine(Directory.GetCurrentDirectory(), "node_modules")),
    RequestPath = "/Modules",        
    OnPrepareResponse = ctx =>
    {
        ctx.Context.Response.Headers.Append("Cache-Control", "public,max-age=600");
    }
});

app.Run();
