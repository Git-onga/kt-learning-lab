// Sample data - in a real app, this would come from an API
const announcementsData = [
    {
        id: 1,
        title: "Semester Registration Deadline Extended",
        excerpt: "The deadline for semester registration has been extended to Friday, October 15th to accommodate all students.",
        category: "academic",
        date: "October 5, 2023",
        author: "Registrar's Office",
        image: "images/registration.jpg"
    },
    {
        id: 2,
        title: "Annual Science and Tech Conference",
        excerpt: "Join us for the 5th Annual Science and Technology Conference featuring keynote speakers from leading tech companies.",
        category: "event",
        date: "October 12, 2023",
        author: "Faculty of Science",
        image: "images/conference.jpg"
    },
    {
        id: 3,
        title: "Library Maintenance Notice",
        excerpt: "The main library will be closed for maintenance from October 8-10. Online resources will remain available.",
        category: "notice",
        date: "October 3, 2023",
        author: "University Library",
        image: "images/library.jpg"
    },
    {
        id: 4,
        title: "Scholarship Application Deadline",
        excerpt: "Applications for the Chancellor's Scholarship must be submitted by October 20th. Don't miss this opportunity!",
        category: "deadline",
        date: "October 1, 2023",
        author: "Financial Aid Office",
        image: "images/scholarship.jpg"
    },
    {
        id: 5,
        title: "Career Fair 2023",
        excerpt: "Over 50 employers will be on campus for our annual Career Fair on November 3rd. Prepare your resumes!",
        category: "event",
        date: "September 28, 2023",
        author: "Career Services",
        image: "images/career-fair.jpg"
    }
];

const spotlightData = [
    {
        id: 1,
        name: "Dr. Wanjiku Mwangi",
        role: "Professor of Computer Science",
        description: "Awarded the National Innovation Prize for her work in AI applications for healthcare.",
        image: "images/professor1.jpg"
    },
    {
        id: 2,
        name: "James Kariuki",
        role: "Student - Mechanical Engineering",
        description: "Designed a solar-powered irrigation system that won first place in the national engineering competition.",
        image: "images/student1.jpg"
    },
    {
        id: 3,
        name: "Tech Innovators Club",
        role: "Student Organization",
        description: "Developed a campus navigation app now being used by the entire university community.",
        image: "images/club1.jpg"
    }
];

// DOM Elements
const announcementsContainer = document.getElementById('announcements-container');
const spotlightContainer = document.getElementById('spotlight-container');
const categoryFilter = document.getElementById('category-filter');
const searchInput = document.querySelector('.search-bar input');
const mobileMenuBtn = document.querySelector('.mobile-menu-btn');
const nav = document.querySelector('.nav');

// Initialize the page
document.addEventListener('DOMContentLoaded', () => {
    renderAnnouncements();
    renderSpotlight();
    setupEventListeners();
});

// Render announcements
function renderAnnouncements(filter = 'all', searchTerm = '') {
    announcementsContainer.innerHTML = '';

    const filtered = announcementsData.filter(announcement => {
        const matchesCategory = filter === 'all' || announcement.category === filter;
        const matchesSearch = announcement.title.toLowerCase().includes(searchTerm.toLowerCase()) || 
                             announcement.excerpt.toLowerCase().includes(searchTerm.toLowerCase());
        return matchesCategory && matchesSearch;
    });

    if (filtered.length === 0) {
        announcementsContainer.innerHTML = '<div class="no-results">No announcements found matching your criteria.</div>';
        return;
    }

    filtered.forEach(announcement => {
        const announcementEl = document.createElement('div');
        announcementEl.className = 'announcement-card';
        announcementEl.innerHTML = `
            <div class="announcement-img">
                <img src="${announcement.image}" alt="${announcement.title}">
            </div>
            <div class="announcement-content">
                <span class="announcement-category">${formatCategory(announcement.category)}</span>
                <h4 class="announcement-title">${announcement.title}</h4>
                <p class="announcement-excerpt">${announcement.excerpt}</p>
                <div class="announcement-meta">
                    <span>${announcement.date}</span>
                    <span>By ${announcement.author}</span>
                </div>
            </div>
        `;
        announcementEl.addEventListener('click', () => {
            window.location.href = `post.html?id=${announcement.id}`;
        });
        announcementsContainer.appendChild(announcementEl);
    });
}

// Render spotlight
function renderSpotlight() {
    spotlightContainer.innerHTML = '';

    spotlightData.forEach(spotlight => {
        const spotlightEl = document.createElement('div');
        spotlightEl.className = 'spotlight-card';
        spotlightEl.innerHTML = `
            <div class="spotlight-img">
                <img src="${spotlight.image}" alt="${spotlight.name}">
            </div>
            <h4 class="spotlight-name">${spotlight.name}</h4>
            <p class="spotlight-role">${spotlight.role}</p>
            <p class="spotlight-desc">${spotlight.description}</p>
            <a href="#" class="btn btn-outline">View Profile</a>
        `;
        spotlightContainer.appendChild(spotlightEl);
    });
}

// Format category for display
function formatCategory(category) {
    const categories = {
        academic: 'Academic',
        event: 'Event',
        notice: 'Notice',
        deadline: 'Deadline'
    };
    return categories[category] || category;
}

// Set up event listeners
function setupEventListeners() {
    // Category filter
    categoryFilter.addEventListener('change', (e) => {
        renderAnnouncements(e.target.value);
    });

    // Search functionality
    searchInput.addEventListener('input', (e) => {
        renderAnnouncements(categoryFilter.value, e.target.value);
    });

    // Mobile menu toggle
    mobileMenuBtn.addEventListener('click', () => {
        nav.classList.toggle('active');
    });
}
