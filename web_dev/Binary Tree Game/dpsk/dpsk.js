// Game State
let tree = null;
let currentMode = null;
let targetNumber = null;
let score = 0;
let currentNode = null;
let currentDifficulty = 3; // Default medium difficulty (depth 5)

// DOM Elements
const treeSvg = document.getElementById('tree-visualization');
const promptEl = document.getElementById('prompt');
const numberDisplay = document.getElementById('number-display');
const feedbackEl = document.getElementById('feedback');
const scoreEl = document.getElementById('score');
const insertModeBtn = document.getElementById('insert-mode');
const guessParentBtn = document.getElementById('guess-parent');
const fixTreeBtn = document.getElementById('fix-tree');
const newTreeBtn = document.getElementById('new-tree');
const difficultySelect = document.createElement('select'); // For difficulty selection

// Binary Tree Node Class
class TreeNode {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
        this.x = 0;
        this.y = 0;
    }
}

// Initialize
document.addEventListener('DOMContentLoaded', () => {
    setupDifficultySelector();
    generateNewTree();
    setupEventListeners();
});

function setupDifficultySelector() {
    difficultySelect.id = 'tree-difficulty';
    
    const difficulties = [
        { value: 3, label: 'Easy (7 nodes)' },
        { value: 4, label: 'Medium (15 nodes)' },
        { value: 5, label: 'Hard (31 nodes)' },
        { value: 6, label: 'Expert (63 nodes)' }
    ];
    
    difficulties.forEach(diff => {
        const option = document.createElement('option');
        option.value = diff.value;
        option.textContent = diff.label;
        difficultySelect.appendChild(option);
    });
    
    difficultySelect.value = currentDifficulty;
    difficultySelect.addEventListener('change', () => {
        currentDifficulty = parseInt(difficultySelect.value);
        generateNewTree();
    });
    
    // Add to controls div
    const controlsDiv = document.querySelector('.controls');
    const label = document.createElement('label');
    label.textContent = 'Difficulty: ';
    label.htmlFor = 'tree-difficulty';
    controlsDiv.insertBefore(label, controlsDiv.firstChild);
    controlsDiv.insertBefore(difficultySelect, controlsDiv.children[1]);
}

// Event Listeners
function setupEventListeners() {
    insertModeBtn.addEventListener('click', () => setMode('insert'));
    guessParentBtn.addEventListener('click', () => setMode('guess-parent'));
    fixTreeBtn.addEventListener('click', () => setMode('fix-tree'));
    newTreeBtn.addEventListener('click', generateNewTree);
}

// Generate a random BST with controlled size
function generateNewTree() {
    const depth = currentDifficulty;
    const nodeCount = Math.pow(2, depth) - 1; // Calculate nodes for perfect tree
    
    // Alternate between balanced and random trees for variety
    if (depth <= 4) {
        tree = generateBalancedBST(nodeCount);
    } else {
        tree = generateRandomBST(depth);
    }
    
    currentMode = null;
    targetNumber = null;
    currentNode = null;
    updateScore(0);
    renderTree();
    promptEl.textContent = "Select a mode to begin!";
    numberDisplay.textContent = "";
    feedbackEl.textContent = "";
}

// Generate a perfectly balanced BST
function generateBalancedBST(nodeCount) {
    const values = [];
    for (let i = 1; i <= nodeCount; i++) {
        values.push(i * 5); // Multiply to space values out
    }
    return sortedArrayToBST(values);
}

function sortedArrayToBST(arr) {
    if (!arr.length) return null;
    
    const mid = Math.floor(arr.length / 2);
    const node = new TreeNode(arr[mid]);
    
    node.left = sortedArrayToBST(arr.slice(0, mid));
    node.right = sortedArrayToBST(arr.slice(mid + 1));
    
    return node;
}

// Generate a random BST with specified depth
function generateRandomBST(depth, min=1, max=100) {
    if (depth === 0) return null;
    
    const value = Math.floor(Math.random() * (max - min + 1)) + min;
    const node = new TreeNode(value);
    
    // Generate left and right subtrees with smaller ranges
    node.left = generateRandomBST(depth - 1, min, value - 1);
    node.right = generateRandomBST(depth - 1, value + 1, max);
    
    return node;
}

// Set game mode
function setMode(mode) {
    currentMode = mode;
    
    switch(mode) {
        case 'insert':
            promptEl.textContent = "Insert the number at the correct position!";
            targetNumber = generateUniqueNumber(tree);
            numberDisplay.textContent = targetNumber;
            feedbackEl.textContent = "";
            break;
            
        case 'guess-parent':
            promptEl.textContent = "Click on what would be the parent node for this number!";
            targetNumber = generateUniqueNumber(tree);
            numberDisplay.textContent = targetNumber;
            feedbackEl.textContent = "";
            break;
            
        case 'fix-tree':
            promptEl.textContent = "Click on nodes to swap and fix the tree!";
            // Intentionally break the tree for this mode
            breakTree();
            targetNumber = null;
            numberDisplay.textContent = "";
            feedbackEl.textContent = "";
            break;
    }
    
    renderTree();
}

function generateUniqueNumber(tree) {
    let num;
    do {
        num = Math.floor(Math.random() * 100) + 1;
    } while (numberExists(tree, num));
    return num;
}

function numberExists(node, num) {
    if (!node) return false;
    if (node.value === num) return true;
    return numberExists(node.left, num) || numberExists(node.right, num);
}

// Break the tree for Fix the Tree mode
function breakTree() {
    // Simple breaking - swap some left/right children
    const nodes = [];
    traverse(tree, node => nodes.push(node));
    
    // Swap a few nodes (more swaps for larger trees)
    const swapCount = Math.min(5, Math.floor(nodes.length / 3));
    for (let i = 0; i < swapCount; i++) {
        const a = Math.floor(Math.random() * nodes.length);
        const b = Math.floor(Math.random() * nodes.length);
        [nodes[a].value, nodes[b].value] = [nodes[b].value, nodes[a].value];
    }
}

// Tree traversal helper
function traverse(node, callback) {
    if (!node) return;
    callback(node);
    traverse(node.left, callback);
    traverse(node.right, callback);
}

// Render the tree using SVG
function renderTree() {
    treeSvg.innerHTML = '';
    
    // Calculate positions based on tree depth
    const depth = getTreeDepth(tree);
    const initialXOffset = 200 * (1 - 0.1 * (depth - 3)); // Adjust for depth
    
    // Calculate positions
    positionNodes(tree, 400, 50, initialXOffset);
    
    // Draw links first (so nodes appear on top)
    drawLinks(tree);
    
    // Draw nodes
    drawNodes(tree);
}

function getTreeDepth(node) {
    if (!node) return 0;
    return 1 + Math.max(getTreeDepth(node.left), getTreeDepth(node.right));
}

function positionNodes(node, x, y, xOffset) {
    if (!node) return;
    
    node.x = x;
    node.y = y;
    
    positionNodes(node.left, x - xOffset, y + 50, xOffset / 2);
    positionNodes(node.right, x + xOffset, y + 50, xOffset / 2);
}

function drawLinks(node) {
    if (!node) return;
    
    if (node.left) {
        const line = document.createElementNS('http://www.w3.org/2000/svg', 'line');
        line.setAttribute('class', 'link');
        line.setAttribute('x1', node.x);
        line.setAttribute('y1', node.y);
        line.setAttribute('x2', node.left.x);
        line.setAttribute('y2', node.left.y);
        treeSvg.appendChild(line);
        drawLinks(node.left);
    }
    
    if (node.right) {
        const line = document.createElementNS('http://www.w3.org/2000/svg', 'line');
        line.setAttribute('class', 'link');
        line.setAttribute('x1', node.x);
        line.setAttribute('y1', node.y);
        line.setAttribute('x2', node.right.x);
        line.setAttribute('y2', node.right.y);
        treeSvg.appendChild(line);
        drawLinks(node.right);
    }
}

function drawNodes(node) {
    if (!node) return;
    
    // Draw circle
    const circle = document.createElementNS('http://www.w3.org/2000/svg', 'circle');
    circle.setAttribute('class', 'node');
    circle.setAttribute('cx', node.x);
    circle.setAttribute('cy', node.y);
    circle.setAttribute('r', 14);
    circle.setAttribute('data-value', node.value);
    
    // Highlight if this is the current node
    if (currentNode && currentNode.value === node.value) {
        circle.setAttribute('class', 'node highlight');
    }
    
    // Add click handler
    circle.addEventListener('click', () => handleNodeClick(node));
    
    treeSvg.appendChild(circle);
    
    // Draw text
    const text = document.createElementNS('http://www.w3.org/2000/svg', 'text');
    text.setAttribute('class', 'node-text');
    text.setAttribute('x', node.x);
    text.setAttribute('y', node.y + 5);
    text.setAttribute('text-anchor', 'middle');
    text.textContent = node.value;
    treeSvg.appendChild(text);
    
    // Recursively draw child nodes
    drawNodes(node.left);
    drawNodes(node.right);
}

// Handle node clicks based on current mode
function handleNodeClick(node) {
    if (!currentMode) return;
    
    switch(currentMode) {
        case 'insert':
            handleInsertMode(node);
            break;
            
        case 'guess-parent':
            handleGuessParentMode(node);
            break;
            
        case 'fix-tree':
            handleFixTreeMode(node);
            break;
    }
}

function handleInsertMode(node) {
    // Check if this is a valid insertion point
    const isValid = (
        // Should be a leaf node
        (!node.left && !node.right) && 
        // And the correct position for targetNumber
        (
            (node.value > targetNumber && (!node.left || node.left.value < targetNumber)) ||
            (node.value < targetNumber && (!node.right || node.right.value > targetNumber))
        )
    );
    
    if (isValid) {
        // Insert the node
        if (targetNumber < node.value) {
            node.left = new TreeNode(targetNumber);
        } else {
            node.right = new TreeNode(targetNumber);
        }
        
        feedbackEl.textContent = "Correct! Number inserted.";
        feedbackEl.style.color = "#2ecc71";
        updateScore(score + 10);
        
        // Generate new target
        setTimeout(() => {
            targetNumber = generateUniqueNumber(tree);
            numberDisplay.textContent = targetNumber;
            feedbackEl.textContent = "";
            renderTree();
        }, 1000);
    } else {
        feedbackEl.textContent = "Incorrect position! Try again.";
        feedbackEl.style.color = "#e74c3c";
        updateScore(Math.max(0, score - 2));
    }
    
    renderTree();
}

function handleGuessParentMode(node) {
    // Check if this would be the parent for targetNumber
    const wouldBeParent = (
        (node.value > targetNumber && (!node.left || node.left.value < targetNumber)) ||
        (node.value < targetNumber && (!node.right || node.right.value > targetNumber))
    );
    
    if (wouldBeParent) {
        feedbackEl.textContent = "Correct! That would be the parent.";
        feedbackEl.style.color = "#2ecc71";
        updateScore(score + 10);
        
        // Generate new target
        setTimeout(() => {
            targetNumber = generateUniqueNumber(tree);
            numberDisplay.textContent = targetNumber;
            feedbackEl.textContent = "";
            renderTree();
        }, 1000);
    } else {
        feedbackEl.textContent = "Incorrect! Try again.";
        feedbackEl.style.color = "#e74c3c";
        updateScore(Math.max(0, score - 2));
    }
}

function handleFixTreeMode(node) {
    if (!currentNode) {
        // First node selected
        currentNode = node;
        renderTree();
    } else {
        // Second node selected - swap values
        [currentNode.value, node.value] = [node.value, currentNode.value];
        currentNode = null;
        
        // Check if tree is valid
        if (isValidBST(tree)) {
            feedbackEl.textContent = "Tree is now valid! Well done!";
            feedbackEl.style.color = "#2ecc71";
            updateScore(score + 20);
        } else {
            feedbackEl.textContent = "Tree is still invalid. Keep trying!";
            feedbackEl.style.color = "#e74c3c";
        }
        
        renderTree();
    }
}

// Check if tree is a valid BST
function isValidBST(node, min=null, max=null) {
    if (!node) return true;
    
    if ((min !== null && node.value <= min) || (max !== null && node.value >= max)) {
        return false;
    }
    
    return isValidBST(node.left, min, node.value) && isValidBST(node.right, node.value, max);
}

function updateScore(newScore) {
    score = newScore;
    scoreEl.textContent = score;
}