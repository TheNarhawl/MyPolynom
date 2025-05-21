<template>
    <div class="ast-node" :class="node.type">
        <div class="node-content">
            <div class="node-type">{{ node.type }}</div>
            <div class="node-text">{{ node.text }}</div>
        </div>
        <div class="node-children" v-if="node.children && node.children.length">
            <div class="connector-line"></div>
            <div class="children-container">
                <AstNode v-for="child in node.children" :key="child.id || child.text" :node="child" />
            </div>
        </div>
    </div>
</template>

<script setup>
import { defineProps } from 'vue'
import AstNode from './AstNode.vue'

defineProps({
    node: {
        type: Object,
        required: true,
    },
})
</script>

<style scoped>
.ast-node {
    margin: 4px 0;
    padding: 10px 12px;
    border-radius: 8px;
    background: white;
    position: relative;
    box-shadow: 0 1px 3px rgba(0, 0, 0, 0.1);
    transition: all 0.2s ease;
    max-width: 500px;
}

.ast-node:hover {
    box-shadow: 0 4px 8px rgba(0, 0, 0, 0.15);
    transform: translateY(-2px);
}

.node-content {
    display: flex;
    gap: 10px;
    align-items: center;
}

.node-type {
    font-size: 12px;
    font-weight: 600;
    color: white;
    padding: 4px 8px;
    border-radius: 12px;
    min-width: 80px;
    text-align: center;
    text-transform: uppercase;
    letter-spacing: 0.5px;
}

.node-text {
    color: #333;
    font-size: 14px;
    font-weight: 500;
    font-family: 'Fira Code', monospace;
}

.node-children {
    margin-left: 24px;
    padding-left: 16px;
    position: relative;
}

.children-container {
    display: flex;
    flex-direction: column;
    gap: 8px;
    padding-top: 8px;
}

.connector-line {
    position: absolute;
    left: 0;
    top: 0;
    bottom: 50%;
    width: 16px;
    border-left: 2px solid #ddd;
    border-bottom: 2px solid #ddd;
    border-bottom-left-radius: 8px;
}

.root .node-type {
    background: linear-gradient(135deg, #6a11cb 0%, #2575fc 100%);
}

.polynomial .node-type {
    background: linear-gradient(135deg, #11998e 0%, #38ef7d 100%);
}

.expression .node-type {
    background: linear-gradient(135deg, #f46b45 0%, #eea849 100%);
}

.term .node-type {
    background: linear-gradient(135deg, #8e2de2 0%, #4a00e0 100%);
}

.factor .node-type {
    background: linear-gradient(135deg, #c31432 0%, #240b36 100%);
}

.variable .node-type {
    background: linear-gradient(135deg, #e65c00 0%, #f9d423 100%);
}

.factor_processing .node-type {
    background: linear-gradient(135deg, #1e3c72 0%, #2a5298 100%);
}

.power .node-type {
    background: linear-gradient(135deg, #ff416c 0%, #ff4b2b 100%);
}

.operator .node-type {
    background: linear-gradient(135deg, #00c6ff 0%, #0072ff 100%);
}

.coefficient .node-type {
    background: linear-gradient(135deg, #614385 0%, #516395 100%);
}

.constant .node-type {
    background: linear-gradient(135deg, #f12711 0%, #f5af19 100%);
}

.variable:hover {
    background-color: #fff9e6;
}

.operator:hover {
    background-color: #f0f9ff;
}

.power:hover {
    background-color: #fff0f0;
}
</style>