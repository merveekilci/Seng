using System.ComponentModel.Design;
using System.Reflection.Metadata;
using CourseApp.Models;
using CourseApp.ViewModels;
using Microsoft.AspNetCore.Authorization.Infrastructure;
using Microsoft.AspNetCore.Mvc;


namespace CourseApp.Controllers
{
    public class CourseController : Controller
    {
        public IActionResult Index(){
            var kurs=new course(){Name="Web Programming", Description="ASP.NET Core MVC", IsOpened=true};

            var ogr=new List<student>(){
                new student(){Name="Deniz"},
                new student(){Name="Ali"},
                new student(){Name="Ahmet"},
                new student(){Name="Ayse"},
                new student(){Name="Sevgi"}
            };
            
            //view model example
            var viewmodel=new CourseStudentsViewModel();
            viewmodel.crs=kurs;
            viewmodel.std=ogr;

            //ViewData["course"]=kurs;
            //ViewBag.course=kurs;
            //ViewBag.count=10;

            return View(viewmodel);           
        }

//examples for returning type

     /*   public IActionResult Index1(){
            return RedirectToAction("list");
        }
        public IActionResult Index2(){
            return NotFound();
        }
        public IActionResult Index3(){
            return Unauthorized();
        }
        public IActionResult Index4(){
            return Redirect("Index");
        }
        public IActionResult Index5(){
            return Content("Hello");
        }   */


        public IActionResult List(){
            var s=Repository.studs.Where(i=> i.Confirm==true);
            return View(s);
        }

        public IActionResult Details(int? id, string? sortby){
            
            /*var course= new course();
            course.Name="ASP.Net Core MVC";
            course.Description="MVC Fundamentals";
            course.IsOpened=true; 
            return View(course);*/

            if(!id.HasValue){
                id=1;
            }
            if(string.IsNullOrWhiteSpace(sortby)){
                sortby="name";
            }
            return Content("id = " + id + " sortby =" +sortby);
        }

        [HttpGet]
        public IActionResult Apply(){   //for only view Apply.cshtml
            return View();       //localhost/course/apply
        }
        [HttpPost]
        public IActionResult Apply(student std){   //for save form data into server
            if(ModelState.IsValid){
                //save data in  repository
                 Repository.AddStudent(std);
                 return View("Thanks", std);   //redirect Thanks.cshtml for listing data
            }
            else{
                return View(std);
            }
           
        }

    public IActionResult ByReleased(int year,int month){
        return Content("year = " +year + " month= "+month );
    }

    }
}