using System.ComponentModel.DataAnnotations;

namespace ModelValidationWeek13.Models
{
    public class Register
    {
        public string UserName { get; set; }
        public string Email { get; set; }
        public string Password { get; set; }

        [UIHint("Date")]
        public DateTime Birthdate { get; set; }
        public bool TermsAccepted { get; set; }
    }
}

