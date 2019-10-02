
const targets = document.querySelectorAll('img');


/*
			Works but bad approach

window.addEventListener('scroll', (event) => {
	targets.forEach(img => {
		const rect = img.getBoundingClientRect().top;
		if(rect <= window.innerHeight) {
			const src = img.getAttribute('data-lazy')
			img.setAttribute('src', src)
			img.classList.add('fade')
		}
	})
})

*/

const lazyLoad = target => {
	const io = new IntersectionObserver((entries, observer) => {
		entries.forEach(entry => {

			if(entry.isIntersecting) {
				const img = entry.target;

				const src = img.getAttribute('data-lazy')

				img.setAttribute('src', src)
				img.classList.add('fade')

				observer.disconnect();
			}
		})
	})

	io.observe(target)
}

targets.forEach(lazyLoad)