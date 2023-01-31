using Microsoft.AspNetCore.Mvc;
using ModelValidationWeek13.Models;

namespace ModelValidationWeek13.Controllers
{
    public class HomeController : Controller
    {
        public IActionResult Index()
        {
            return View("Register", new Register() { Birthdate = DateTime.Now });
        }

        public IActionResult Register(Register model)
        {
            if (string.IsNullOrEmpty(model.UserName))
            {
                ModelState.AddModelError(nameof(model.UserName), "User name is compulsory field.");
            }


            if (string.IsNullOrEmpty(model.Email))
            {
                ModelState.AddModelError(nameof(model.Email), "Email is compulsory field.");
            }
            else
            {
                if (!model.Email.Contains("@"))
                {
                    ModelState.AddModelError(nameof(model.Email), "Email address is not right format.");
                }
            }

            if (string.IsNullOrEmpty(model.Password))
            {
                ModelState.AddModelError(nameof(model.Password), "Password is compulsory field.");
            }
            else
            {
                if(model.Password.Length<6)
                {
                    ModelState.AddModelError(nameof(model.Password), "Password must not be less than 6 characters.");
                }
            }

            if (!model.TermsAccepted)
            {
                ModelState.AddModelError(nameof(model.TermsAccepted), "You have to accept the conditions. ");
            }


            if (ModelState.IsValid)
            {
                return View("Completed", model);
            }
            else {
                return View(model);
            }


            
        }
    }
}
