/* Hamburger Menu Animation */
document.addEventListener("DOMContentLoaded", function(){

    const toggleButton = document.getElementsByClassName('toggle-button')[0];
    const navbarLinks = document.getElementsByClassName('navBar-links')[0];
    toggleButton.addEventListener('click', () => {
        navbarLinks.classList.toggle('active');
    });
});


/* Scroll Animation */
const observer = new IntersectionObserver(entries => {
    entries.forEach(entry => {
        console.log(entry)
        if (entry.isIntersecting) {
            entry.target.classList.toggle('show');
        } else {
            entry.target.classList.remove('show');
        }
    });
});

const hiddenTop = document.querySelectorAll('.hiddenTop');
const hiddenRight = document.querySelectorAll('.hiddenRight');
const hiddenBottom = document.querySelectorAll('.hiddenBottom');
const hiddenLeft = document.querySelectorAll('.hiddenLeft');
hiddenTop.forEach((el) => observer.observe(el));
hiddenRight.forEach((el) => observer.observe(el));
hiddenBottom.forEach((el) => observer.observe(el));
hiddenLeft.forEach((el) => observer.observe(el));