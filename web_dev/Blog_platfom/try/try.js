// Sample data for the newspaper
const newsData = {
    leadStory: {
        id: 1,
        title: "5th Annual Science and Tech Conference Kicks Off Tomorrow",
        excerpt: "The university prepares to welcome leading researchers and innovators for three days of cutting-edge presentations and workshops. Over 500 attendees expected for this year's event themed 'Innovation for Sustainable Development.'",
        category: "FEATURED EVENT",
        date: "October 9, 2023",
        author: "James Mwangi",
        comments: 14,
        image: "images/lead-story.jpg",
        caption: "Keynote speaker Dr. Wanjiru at last year's conference"
    },
    stories: [
        {
            id: 2,
            title: "Registration Deadline Extended to October 15",
            excerpt: "The university administration has announced a one-week extension for semester registration to accommodate students experiencing technical difficulties.",
            category: "ACADEMICS",
            date: "October 8, 2023",
            image: "images/registration.jpg"
        },
        {
            id: 3,
            title: "Basketball Team Advances to Nationals",
            excerpt: "After a thrilling regional championship win, our men's basketball team will represent the university at the national championships next month.",
            category: "SPORTS",
            date: "October 7, 2023",
            image: "images/basketball.jpg"
        },
        {
            id: 4,
            title: "Drama Club Presents 'The Trials of Life'",
            excerpt: "The university drama club will perform their original production this weekend in the main auditorium. Tickets available at the student center.",
            category: "ARTS",
            date: "October 6, 2023",
            image: "images/drama.jpg"
        }
    ],
    spotlights: [
        {
            id: 1,
            title: "Dr. Wanjiku Wins Innovation Prize",
            excerpt: "Computer Science professor recognized for her groundbreaking work in AI applications for healthcare.",
            image: "images/spotlight1.jpg"
        },
        {
            id: 2,
            title: "Students Develop Solar Irrigation System",
            excerpt: "Engineering team's project wins national competition and attracts commercial interest.",
            image: "images/spotlight2.jpg"
        }
    ],
    opinions: [
        {
            id: 1,
            title: "Time to Upgrade Our Library Facilities",
            excerpt: "With the recent maintenance closure highlighting our aging infrastructure, we argue for immediate investment in library upgrades.",
            author: "Editorial Board",
            image: "images/opinion1.jpg"
        },
        {
            id: 2,
            title: "Why We Need More Parking Spaces",
            excerpt: "A third-year engineering student makes the case for expanding campus parking as enrollment grows.",
            author: "Student Voice",
            image: "images/opinion2.jpg"
        }
    ]
};

// DOM Elements
const currentDate = document.querySelector('.date');
const leadStorySection = document.querySelector('.lead-story');
const storiesContainer = document.querySelector('.secondary-stories');
const spotlightContainer = document.querySelector('.spotlight-grid');
const opinionContainer = document.querySelector('.opinion-grid');
const searchInput = document.querySelector('.search-mobile input');
const mobileMenuBtn = document.querySelector('.mobile-menu-btn');
const nav = document.querySelector('.newspaper-nav ul');

// Initialize the newspaper
document.addEventListener('DOMContentLoaded', () => {
    setCurrentDate();
    renderLeadStory();
    renderStories();
    renderSpotlights();
    renderOpinions();
    setupEventListeners();
});

// Set current date
function setCurrentDate() {
    const options = { weekday: 'long', year: 'numeric', month: 'long', day: 'numeric' };
    const today = new Date();
    currentDate.textContent = today.toLocaleDateString('en-US', options);
}

// Render lead story
function renderLeadStory() {
    const story = newsData.leadStory;
    leadStorySection.innerHTML = `
        <figure>
            <img src="${story.image}" alt="${story.title}">
            <figcaption>${story.caption}</figcaption>
        </figure>
        <div class="story-content">
            <span class="category-tag">${story.category}</span>
            <h2><a href="article.html?id=${story.id}">${story.title}</a></h2>
            <p class="excerpt">${story.excerpt}</p>
            <div class="story-meta">
                <span>By ${story.author}</span>
                <span>${story.date}</span>
                <span><i class="far fa-comment"></i> ${story.comments}</span>
            </div>
        </div>
    `;
}

// Render secondary stories
function renderStories() {
    storiesContainer.innerHTML = newsData.stories.map(story => `
        <article class="story-card">
            <span class="category-tag">${story.category}</span>
            <h3><a href="article.html?id=${story.id}">${story.title}</a></h3>
            <p class="excerpt">${story.excerpt}</p>
            <div class="story-meta">
                <span>${story.date}</span>
            </div>
        </article>
    `).join('');
}

// Render spotlights
function renderSpotlights() {
    spotlightContainer.innerHTML = newsData.spotlights.map(spotlight => `
        <article class="spotlight-card">
            <img src="${spotlight.image}" alt="${spotlight.title}">
            <div class="spotlight-content">
                <h3>${spotlight.title}</h3>
                <p>${spotlight.excerpt}</p>
                <a href="#" class="read-more">Read Profile <i class="fas fa-arrow-right"></i></a>
            </div>
        </article>
    `).join('');
}

// Render opinions
function renderOpinions() {
    opinionContainer.innerHTML = newsData.opinions.map(opinion => `
        <article class="opinion-card">
            <div class="opinion-meta">
                <img src="${opinion.image}" alt="${opinion.author}">
                <span>${opinion.author}</span>
            </div>
            <h3><a href="article.html?id=${opinion.id}">${opinion.title}</a></h3>
            <p class="excerpt">${opinion.excerpt}</p>
        </article>
    `).join('');
}

// Set up event listeners
function setupEventListeners() {
    // Mobile menu toggle
    mobileMenuBtn.addEventListener('click', () => {
        nav.style.display = nav.style.display === 'flex' ? 'none' : 'flex';
    });

    // Search functionality
    searchInput.addEventListener('keyup', (e) => {
        if (e.key === 'Enter') {
            const searchTerm = e.target.value.toLowerCase();
            if (searchTerm) {
                // In a real app, this would filter articles from an API
                alert(`Searching for: ${searchTerm}`);
                e.target.value = '';
            }
        }
    });

    // Close mobile menu when clicking outside
    document.addEventListener('click', (e) => {
        if (!nav.contains(e.target) && e.target !== mobileMenuBtn) {
            nav.style.display = 'none';
        }
    });
}
