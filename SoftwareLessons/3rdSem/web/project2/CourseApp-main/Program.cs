var builder = WebApplication.CreateBuilder(args);
builder.Services.AddControllers();
builder.Services.AddRazorPages();
var app = builder.Build();

//app.MapGet("/", () => "Hello World!");

app.UseRouting();
app.UseEndpoints(endpoints =>
{
    endpoints.MapControllerRoute(
        name: "default",
        pattern: "{controller=home}/{action=index}/{id?}" // "? = optional"
    );
    
    endpoints.MapRazorPages();
});





app.Run();
